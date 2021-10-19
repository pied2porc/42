#define _CRT_SECURE_NO_WARNINGS
#include "Account.class.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int Account::_nbAccounts        { 0 };
int Account::_totalAmount       { 0 };
int Account::_totalNbDeposits   { 0 };
int Account::_totalNbWithdrawals{ 0 };
int Account::_checkAmountCalls  { 0 };

Account::Account(int initial_deposit) :
    _accountIndex{ _nbAccounts++ }, _amount{ initial_deposit },
    _nbDeposits{ 0 }, _nbWithdrawals{ 0 }
{
    _totalAmount += _amount;
    _displayTimestamp();
    std::cout << "index:"  << _accountIndex << ';';
    std::cout << "amount:" << _amount << ';';
    std::cout << "created\n";
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:"  << _accountIndex << ';';
    std::cout << "amount:" << _amount << ';';
    std::cout << "closed\n";
}

int Account::getNbAccounts()    { return _nbAccounts; }
int Account::getTotalAmount()   { return _totalAmount; }
int Account::getNbDeposits()    { return _totalNbDeposits; }
int Account::getNbWithdrawals() { return _totalNbWithdrawals; }

void Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << "accounts:"    << _nbAccounts << ';';
    std::cout << "total:"       << _totalAmount << ';';
    std::cout << "deposits:"    << _totalNbDeposits << ';';
    std::cout << "withdrawals:" << _totalNbWithdrawals << '\n';
}

void Account::_displayTimestamp(void)
{
    auto now{ std::time(nullptr) };
    auto tm{ *std::localtime(&now) };
    std::cout << std::put_time(&tm, "[%Y%m%d_%H%M%S] ");
}

void Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:"    << _accountIndex << ';';
    std::cout << "p_amount:" << _amount << ';';
    std::cout << "deposit:"  << deposit << ';';

    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++; _totalNbDeposits++;

    std::cout << "amount:"      << _amount << ';';
    std::cout << "nb_deposits:" << _nbDeposits << '\n';
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:"    << _accountIndex << ';';
    std::cout << "p_amount:" << _amount << ';';
    std::cout << "withdrawal:";
    if (withdrawal <= _amount) {
        std::cout << withdrawal << ';';

        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        _nbWithdrawals++; _totalNbWithdrawals++;

        std::cout << "amount:"        << _amount << ';';
        std::cout << "nb_withdrawal:" << _nbWithdrawals << '\n';
        return true;
    }
    std::cout << "refused\n";
    return false;
}

int Account::checkAmount(void) const
{
    _checkAmountCalls++;
    return _amount;
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:"       << _accountIndex << ';';
    std::cout << "amount:"      << _amount << ';';
    std::cout << "deposits:"    << _nbDeposits << ';';
    std::cout << "withdrawals:" << _nbWithdrawals << '\n';
}