#include "Account.hpp"
#include <string>
#include <iostream>
#include <ctime>
#include <iomanip>

int	Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/* ============ Constructor & Destructor ============ */

Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts++;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";amount:" << initial_deposit
			<< ";created" << '\n';
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			<< ";amount:" << this->_amount
			<< ";closed" << '\n';
}

/* ==================== Getter ==================== */

int Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

/* ================ Withdraw and deposit ================ */

void	Account::makeDeposit( int deposit )
{
	this->_nbDeposits += 1;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			<<";p_amount:" << this->_amount;
	this->_amount += deposit;
	std::cout << ";deposit:" << deposit
			<< ";amount:" << this->_amount
			<< ";nb_deposit:" << this->_nbDeposits << '\n';
	_totalAmount += deposit;
	_totalNbDeposits += 1;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	if (withdrawal > this->_amount)
	{
		std::cout << "index:" << this->_accountIndex
				<< ";p_amount:" << this->_amount
				<< ";withdrawal:refused" << '\n';
		return (false);
	}
	std::cout << "index:" << this->_accountIndex
			<< ";p_amount:" << this->_amount
			<< ";withdrawal:" << withdrawal;
	this->_amount -= withdrawal;
	std::cout << ";amount:" << this->_amount;
	this->_nbWithdrawals += 1;
	std::cout << ";nb_Withdrawals:" << this->_nbWithdrawals << '\n';
	_totalAmount -= withdrawal;
	_totalNbWithdrawals += 1;
	return (true);
}

/* ================ Display and Check ================ */

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			<< ";amount:" << this->_amount
			<< ";deposits:" << this->_nbDeposits
			<< ";withdrawals:" << this->_nbWithdrawals << '\n';
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
			 << ";total:" << _totalAmount
			 << ";deposits:" << _totalNbDeposits
			 << ";withdrawals:" << _totalNbWithdrawals << '\n';
}

void	Account::_displayTimestamp(void)
{
	std::time_t time = std::time(0);
	std::tm	now = *std::localtime(&time);
	std::cout
			<< "["
			<< now.tm_year + 1900
			<< std::setfill('0')
			<< std::setw(2) << now.tm_mon + 1
			<< std::setw(2) << now.tm_mday << "_"
			<< std::setw(2) << now.tm_hour
			<< std::setw(2) << now.tm_min
			<< std::setw(2) << now.tm_sec
			<< "] ";
}