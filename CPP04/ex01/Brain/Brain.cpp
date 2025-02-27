/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 07:27:24 by tclaereb          #+#    #+#             */
/*   Updated: 2025/02/27 14:04:08 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void ) {
	LOGC( GREEN ) << "Brain default constructor";

	for ( int i = 0; i < 100; i++ ) {
		this->_ideas[ i ] = "";
	}
}

Brain::~Brain( void ) {
	LOGC( RED ) << "Brain destructor";
}

Brain::Brain( Brain const &other ) {
	LOGC( GREEN ) << "Brain copy constructor";

	std::string const*	otherIdeas = other.getIdeas();

	for ( int i = 0; i < 100; i++ ) {
		this->setIdeas( otherIdeas[ i ], i );
	}
}

Brain&	Brain::operator=( Brain const &other ) {
	LOGC( YELLOW ) << "Brain assignement overload";

	std::string const*	otherIdeas = other.getIdeas();

	for ( int i = 0; i < 100; i++ ) {
		this->setIdeas( otherIdeas[ i ], i );
	}

	return ( *this );
}

std::string const*	Brain::getIdeas( void ) const {
	return ( this->_ideas );
}

void	Brain::setIdeas( std::string idea, unsigned int idx ) {
	this->_ideas[ idx ] = idea;
}
