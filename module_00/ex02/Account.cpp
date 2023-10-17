/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:49:32 by dohanyan          #+#    #+#             */
/*   Updated: 2023/09/09 20:59:32 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
	_displayTimestamp();
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this -> _accountIndex = _nbAccounts++;
	_totalAmount += this->_amount;
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;     
	
}

Account::~Account ( void )
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}

void Account::_displayTimestamp(void)
{
	struct tm* 		tm;
	time_t			start;
	
	start = time(0);
  	tm = localtime ( &start );
	std::cout << "[";
	std::cout << tm->tm_year + 1900;
	std::cout << std::setw(2) << std::setfill('0');
	std::cout << tm->tm_mday;
	std::cout << std::setw(2) << std::setfill('0');
	std::cout << tm->tm_mon + 1;
	std::cout << "_";
	std::cout << std::setw(2) << std::setfill('0');
	std::cout << tm->tm_hour;
	std::cout << std::setw(2) << std::setfill('0');
	std::cout << tm->tm_min;
	std::cout << std::setw(2) << std::setfill('0');
	std::cout << tm->tm_sec;
	std::cout << "]";
}

void Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << " accounts:"<<_nbAccounts << ";";
	std::cout << "total:" <<_totalAmount << ";";
	std::cout << "deposits:" <<_totalNbDeposits <<";";
	std::cout << "withdrawals:" <<_totalNbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	_totalNbDeposits++;
	_nbDeposits++;
	std::cout << " index:" <<_accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "deposit:" << deposit << ";";
	_amount += deposit;
	std::cout << "amount:"<< _amount << ";";
	std::cout << "nb_deposits:" <<_nbDeposits << std::endl;
	_totalAmount += _amount;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "withdrawal:";
	_amount -=withdrawal;
	if (!checkAmount())
	{
		_amount += withdrawal;
		std::cout << "refused" << std::endl;
		_totalAmount += _amount;
		return (false);
	}
	_totalNbWithdrawals++;
	_totalAmount += _amount;
 	std::cout << withdrawal << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_withdrawals:" << ++_nbWithdrawals << std::endl;
	return (true);
	
}

void Account::displayStatus(void)const
{
	_displayTimestamp();
	_totalAmount = 0;
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

int Account::checkAmount(void)const
{
	return (!(this->_amount <= 0));
}

int Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}