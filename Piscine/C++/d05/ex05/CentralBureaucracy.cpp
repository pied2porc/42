#include "CentralBureaucracy.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"

using CB = CentralBureaucracy;
CB::CentralBureaucracy() {}
CB::~CentralBureaucracy()
{
    for (auto& b : _blocks){
        delete b.getSigner();
        delete b.getExecutor();
    }
}

CB::CentralBureaucracy(CentralBureaucracy const& src) { *this = src; }
CB& CB::operator=(CentralBureaucracy const&) { return *this; }

void CB::feed(Bureaucrat* slave)
{
    if (_slavesCount > (_maxBlock * 2) - 1){
        std::cerr << *slave << " has been rejected. No seats available.\n";
        delete slave;
        return;
    }
    if ((_slavesCount % 2) == 0)
        _blocks[_slavesCount / 2].setSigner(*slave);
    else
        _blocks[_slavesCount / 2].setExecutor(*slave);
    ++_slavesCount;
}

void CB::queueUp(str_t const& name)
{
    if (!_head) {
        _head = new t_queue{ name };
        _tail = _head;
        return;
    }
    _tail->next = new t_queue{ name };
    _tail = _tail->next;
}

void CB::dequeue()
{
    if (!_head) return;

    t_queue* toDelete{ _head };
    _head = _head->next;
    if (!_head)
        _tail = nullptr;
    delete toDelete;
}

void CB::doBureaucracy()
{
    static str_t forms[]{ PresidentialPardonForm::_name,
                          RobotomyRequestForm::_name,
                          ShrubberyCreationForm::_name,
                          "Pay Raise Request",
                          "Right to Fart in Public",
                          "Improper Request" };
    int size{ sizeof(forms) / sizeof(*forms) };
    static double constexpr fraction{ 1.0 / (RAND_MAX + 1.0) };
    
    for (int i{ 0 }; _head; ++i) {
        if (i == _maxBlock) i = 0;
        int idx{ static_cast<int>(std::rand() * fraction * size) };
        _blocks[i].setIntern(_intern);
        try {
            _blocks[i].doBureaucracy(forms[idx], _head->name);
            std::cout << "\t\t\t*\t*\t*\n";
        }
        catch (OfficeBlock::MissingInternException& e) {
            std::cerr << e.what() << ".\n";
        }
        catch (OfficeBlock::MissingSignerException& e) {
            std::cerr << e.what() << ".\n";
        }
        catch (OfficeBlock::MissingExecutorException& e) {
            std::cerr << e.what() << ".\n";
        }
        catch (Form::UnsignedException& e) {
            std::cerr << " because " << e.what() << ".\n";
            std::cout << "\t\t\t*\t*\t*\n";
        }
        catch (Intern::UnknownFormException& e) {
            std::cerr << e.what() << ".\n";
            std::cout << "\t\t\t*\t*\t*\n";
        }
        catch (Bureaucrat::SignException& e) {
            std::cerr << " because " << e.what() << ".\n";
            std::cout << "\t\t\t*\t*\t*\n";
        }
        catch (Bureaucrat::ExecuteException& e) {
            std::cerr << " because " << e.what() << ".\n";
            std::cout << "\t\t\t*\t*\t*\n";
        }
        catch (std::exception& e) {
            std::cerr << "Unknown error: " << e.what() << ".\n";
        }
        dequeue();
    }
}