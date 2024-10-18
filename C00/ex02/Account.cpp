/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Théo <theoclaereboudt@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 21:54:36 by Théo              #+#    #+#             */
/*   Updated: 2024/10/18 23:38:00 by Théo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

// Static init
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void ) {
	time_t		timestamp	= time(NULL);
	struct tm	datetime	= *localtime(&timestamp);
	char		output[50];

	strftime(output, 50, "%Y%m%d_%H%M%S", &datetime);
	std::cout << "[" << output << "] ";
}

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << "\n";
}

// Class init
Account::Account( int deposit ) : _nbDeposits(0), _nbWithdrawals(0) {
	this->_accountIndex	= _nbAccounts;
	this->_amount		= deposit;

	_nbAccounts			+= 1;
	_totalAmount		+= deposit;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" << "amount:" << this->_amount << ";created\n";
}

Account::~Account( void ) {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed\n";
}

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" << "amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << "\n";
}

void	Account::makeDeposit( int deposit ) {
	int	lastAmount		= this->_amount;
	this->_amount		+= deposit;
	this->_nbDeposits	+= 1;
	_totalNbDeposits	+= 1;
	_totalAmount		+= deposit;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amout:" << lastAmount << ";deposit:" << deposit << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << "\n";
}


bool	Account::makeWithdrawal( int withdrawal ) {
	int	lastAmount			= this->_amount;
	int	newAmount			= lastAmount - withdrawal;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << lastAmount << ";withdrawal:";
	if (newAmount < 0) {
		std::cout << "refused\n";
		return (false);
	}
	this->_amount			= newAmount;
	this->_nbWithdrawals	+= 1;
	_totalNbWithdrawals		+= 1;
	_totalAmount			-= withdrawal;

	std::cout << withdrawal << ";amount:" << newAmount << ";nb_withdrawals:" << this->_nbWithdrawals << "\n";
	return (true);
}

