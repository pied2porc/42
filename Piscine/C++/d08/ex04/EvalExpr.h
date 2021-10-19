#pragma once
#include "Token.h"
#include <iostream>
#include <string>
#include <vector>

class EvalExpr
{
private:
    std::vector<Token*> _tokens{};
    std::vector<Token*> _postfix{};
    long                _result{};
    size_t              _maxDigits{};

public:
    EvalExpr();
    ~EvalExpr();
    EvalExpr(EvalExpr const&);
    EvalExpr& operator=(EvalExpr const&);

    std::vector<Token*>const& getTokens() const;
    std::vector<Token*>const& getPostfix() const;
    long                      getResult() const;

    void tokenize(std::string const&);
    void postfix();
    void eval();
    int  precedence(int) const;
    void transferOp(std::vector<Token*>&);
    void printStep(Token const&, std::vector<int> const&) const;
};