#include "EvalExpr.h"
#include "Token.h"
#include <cstring>
#include <exception>
#include <iomanip>
#include <string>

EvalExpr::EvalExpr() {}
EvalExpr::~EvalExpr() { for (auto& t : _tokens) delete t; }
EvalExpr::EvalExpr(EvalExpr const& src) { *this = src; }
EvalExpr& EvalExpr::operator=(EvalExpr const& rhs)
{
    if (this == &rhs) return *this;
    _tokens = rhs._tokens;
    _postfix = rhs._postfix;
    _result = rhs._result;
    return *this;
}

std::vector<Token*>const& EvalExpr::getTokens() const { return _tokens; }
std::vector<Token*>const& EvalExpr::getPostfix() const { return _postfix; }
long                      EvalExpr::getResult() const { return _result; }

void EvalExpr::tokenize(std::string const& expr)
{
    auto begin{ expr.begin() };
    auto end{ expr.end() };
    auto it{ begin };
    while (it != end) {
        if (*it >= '0' && *it <= '9') {
            size_t pos{};
            _tokens.push_back(new Number(std::stoi(expr.substr(it - begin), &pos)));
            it += pos;
            static_cast<Number*>(_tokens.back())->setDigits(pos);
            if (pos > _maxDigits) _maxDigits = pos;
        }
        else {
            if (*it == '(' || *it == ')')
                _tokens.push_back(new Parenthesis(*it));
            else if (std::strchr("+-/*", *it))
                _tokens.push_back(new Operator(*it));
            ++it;
        }
    }
}

void EvalExpr::postfix()
{
    std::vector<Token*> op;
    int parOpen{ 0 }, parClose{ 0 };
    for (auto& t : _tokens) {
        if (t->getType() == "Num")
            _postfix.push_back(t);
        else if (t->getType() == "Par" && t->getValue() == '(') {
            ++parOpen;
            op.push_back(t);
        }
        else if (t->getType() == "Par" && t->getValue() == ')') {
            ++parClose;
            while (!op.empty() && !(op.back()->getType() == "Par"))
                transferOp(op);
            if (op.empty()) throw std::runtime_error("missing parenthesis");
            op.pop_back();
        }
        else {
            while (!op.empty() &&
                precedence(t->getValue()) <= precedence(op.back()->getValue()))
                transferOp(op);
            op.push_back(t);
        }
    }
    if (parOpen != parClose) throw std::runtime_error("missing parenthesis");
    while (!op.empty())
        transferOp(op);
}

void EvalExpr::eval()
{
    std::vector<int> stack;
    for (auto& t : _postfix) {
        if (t->getType() == "Num")
            stack.push_back(t->getValue());
        else {
            int rhs{ stack.back() }; stack.pop_back();
            int lhs{ stack.back() }; stack.pop_back();
            int res{};
            switch (t->getValue()) {
            case '+': res = lhs + rhs; break;
            case '-': res = lhs - rhs; break;
            case '*': res = lhs * rhs; break;
            case '/': if (!rhs) throw std::runtime_error("divide by zero");
                      res = lhs / rhs; break;
            }
            stack.push_back(res);
        }
        printStep(*t, stack);
    }
    _result = stack.empty() ? 0 : stack.back();
}

int EvalExpr::precedence(int op) const
{
    switch (op) {
    case '+':
    case '-': return 0;
    case '*':
    case '/': return 1;
    default: return -1;
    }
}

void EvalExpr::transferOp(std::vector<Token*>& op)
{
    _postfix.push_back(op.back());
    op.pop_back();
}

void EvalExpr::printStep(Token const& t, std::vector<int> const& stack) const
{
    /* current input & resulting operation */
    std::string type{ t.getType() };
    size_t width{ 2 };
    std::string op;
    if (type == "Num") {
        size_t digits{ static_cast<Number const&>(t).getDigits() };
        width += _maxDigits - digits;
        op = "Push";
    }
    else {
        width += _maxDigits;
        switch (t.getValue()) {
        case '+': op = "Add"; break;
        case '-': op = "Substract"; break;
        case '*': op = "Multiply"; break;
        case '/': op = "Divide"; break;
        }
    }
    std::cout << "\nI " << t << std::setw(width) << "|";
    std::cout << " OP " << op << std::setw(11 - op.size()) << "|";

    /* stack state */
    std::cout << " ST ";
    auto begin{ stack.begin() };
    auto it{ stack.end() };
    while (--it != begin)
        std::cout << *it << ' ';
    std::cout << *it << ' ';
    std::cout << "\b]";
}