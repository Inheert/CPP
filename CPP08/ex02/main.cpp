/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 09:48:22 by tclaereb          #+#    #+#             */
/*   Updated: 2025/10/31 14:08:55 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/proto.hpp"

void	mutantStackPush( MutantStack< int > &stack, int n ) {
	stack.push( n );
}

void listPush( std::list< int > &lst, int n ) {
	lst.push_back( n );
}

int	mutantStackTop( MutantStack< int > &stack ) {
	return ( stack.top() );
}

int	listTop( std::list< int > &lst ) {
	return ( lst.back() );
}

void	mutantStackPop( MutantStack< int > &stack ) {
	stack.pop();
}

void listPop( std::list< int > &lst ) {
	lst.pop_back();
}

int main() {
	MutantStack< int >	ms;
	std::list< int >	lst;

	testContainer( ms, "MUTANT STACK CHECK", mutantStackPush, mutantStackTop, mutantStackPop );
	testContainer( lst, "LIST CHECK", listPush, listTop, listPop );
}
