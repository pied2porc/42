#pragma once
#include "Bureaucrat.h"
#include "Intern.h"
#include <string>

using str_t = std::string;

class OfficeBlock
{
    Intern*     _noob{ nullptr };
    Bureaucrat* _signer{ nullptr };
    Bureaucrat* _exec{ nullptr };

public:
    OfficeBlock();
    OfficeBlock(Intern&, Bureaucrat&, Bureaucrat&);
    ~OfficeBlock();

    OfficeBlock(OfficeBlock const&) = delete;
    OfficeBlock& operator=(OfficeBlock const&) = delete;

    Intern*     getIntern() const;
    Bureaucrat* getSigner() const;
    Bureaucrat* getExecutor() const;
    void        setIntern(Intern&);
    void        setSigner(Bureaucrat&);
    void        setExecutor(Bureaucrat&);

    void doBureaucracy(str_t const&, str_t const&) const;

    class MissingInternException : public std::exception
    {
    public:
        MissingInternException();
        ~MissingInternException();
        MissingInternException(MissingInternException const&);
        MissingInternException& operator=(MissingInternException const&);

        char const* what() const noexcept;
    };

    class MissingSignerException : public std::exception
    {
    public:
        MissingSignerException();
        ~MissingSignerException();
        MissingSignerException(MissingSignerException const&);
        MissingSignerException& operator=(MissingSignerException const&);

        char const* what() const noexcept;
    };

    class MissingExecutorException : public std::exception
    {
    public:
        MissingExecutorException();
        ~MissingExecutorException();
        MissingExecutorException(MissingExecutorException const&);
        MissingExecutorException& operator=(MissingExecutorException const&);

        char const* what() const noexcept;
    };
};