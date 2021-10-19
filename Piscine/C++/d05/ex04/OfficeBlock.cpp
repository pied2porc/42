#include "OfficeBlock.h"

OfficeBlock::OfficeBlock() {}
OfficeBlock::OfficeBlock(Intern& intern,
                         Bureaucrat& signer,
                         Bureaucrat& exec) :
    _noob{ &intern }, _signer{ &signer }, _exec{ &exec } {}

OfficeBlock::~OfficeBlock() {}

Intern*     OfficeBlock::getIntern() const { return _noob; }
Bureaucrat* OfficeBlock::getSigner() const { return _signer; }
Bureaucrat* OfficeBlock::getExecutor() const { return _exec; }
void OfficeBlock::setIntern(Intern& i) { _noob = &i; }
void OfficeBlock::setSigner(Bureaucrat& s) { _signer = &s; }
void OfficeBlock::setExecutor(Bureaucrat& e) { _exec = &e; }

/* Member Functions */
void OfficeBlock::doBureaucracy(str_t const& fname, str_t const& target) const
{
    if (!_noob)
        throw MissingInternException();
    if (!_signer)
        throw MissingSignerException();
    if (!_exec)
        throw MissingExecutorException();
        
    try {
        Form& form{ *(_noob->makeForm(fname, target)) };
        _signer->signForm(form);
        _exec->executeForm(form);
    }
    catch (std::exception&) {
        throw;
    }
}

/* Exceptions */
using O_MIE = OfficeBlock::MissingInternException;
O_MIE::MissingInternException() {}
O_MIE::~MissingInternException() {}
O_MIE::MissingInternException(MissingInternException const& src) { *this = src; }
O_MIE& O_MIE::operator=(MissingInternException const&) { return *this; }

char const* O_MIE::what() const noexcept { return "Intern is missing"; }

using O_MSE = OfficeBlock::MissingSignerException;
O_MSE::MissingSignerException() {}
O_MSE::~MissingSignerException() {}
O_MSE::MissingSignerException(MissingSignerException const& src) { *this = src; }
O_MSE& O_MSE::operator=(MissingSignerException const&) { return *this; }

char const* O_MSE::what() const noexcept { return "Signer is missing"; }

using O_MEE = OfficeBlock::MissingExecutorException;
O_MEE::MissingExecutorException() {}
O_MEE::~MissingExecutorException() {}
O_MEE::MissingExecutorException(MissingExecutorException const& src) { *this = src; }
O_MEE& O_MEE::operator=(MissingExecutorException const&) { return *this; }

char const* O_MEE::what() const noexcept { return "Executor is missing"; }