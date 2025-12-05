/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:22:09 by tclaereb          #+#    #+#             */
/*   Updated: 2025/12/05 12:53:08 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
	jacobstahlVector();
	jacobstahlList();
	_elapsedVector = 0.0;
	_elapsedList = 0.0;
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe( const PmergeMe& other ) : _elapsedVector( other._elapsedVector ),
	_elapsedList( other._elapsedList ), _jacobstahlVector( other._jacobstahlVector ),
	_jacobstahlList( other._jacobstahlList )
{}

PmergeMe& PmergeMe::operator=( const PmergeMe& other ) {
	if ( this == &other )
		return ( *this );

	_elapsedVector = other._elapsedVector;
	_elapsedList = other._elapsedList;
	_jacobstahlVector = other._jacobstahlVector;
	_jacobstahlList = other._jacobstahlList;
	return ( *this );
}

void PmergeMe::jacobstahlVector() {
	_jacobstahlVector.clear();
	_jacobstahlVector.push_back( 0 );
	_jacobstahlVector.push_back( 1 );
	for ( size_t i = 2; i < 50; ++i ) {
		size_t un = _jacobstahlVector[ i - 1 ] + 2 * _jacobstahlVector[ i - 2 ];
		_jacobstahlVector.push_back( un );
	}
}

void PmergeMe::jacobstahlList() {
	_jacobstahlList.clear();
	_jacobstahlList.push_back(0);
	_jacobstahlList.push_back(1);
	size_t u1 = 0;
	size_t u2 = 1;
	for ( size_t i = 2; i < 50; ++i ) {
		size_t un = u2 + 2 * u1;
		_jacobstahlList.push_back( un );
		u1 = u2;
		u2 = un;
	}
}

std::vector< size_t > PmergeMe::insert( size_t pendSize ) {
	std::vector< size_t > order;
	if ( pendSize == 0 )
		return ( order );
	order.push_back( 0 );
	if ( pendSize == 1 )
		return ( order );

	size_t k = 2;
	while ( order.size() < pendSize ) {
		size_t j;
		if ( k < _jacobstahlVector.size() )
			j = _jacobstahlVector[ k ];
		else
			j = pendSize;

		size_t start;
		if ( j == 0 )
			start = 0;
		else {
			if ( j - 1 < pendSize - 1 )
				start = j - 1;
			else
				start = pendSize - 1;
		}

		size_t end = order.size();

		for (int i = static_cast< int >( start ); i >= static_cast<int>( end ); --i ) {
			if ( static_cast< size_t >( i ) < pendSize ) {
				order.push_back( static_cast< size_t >( i ) );
				if ( order.size() >= pendSize )
					break;
			}
			if ( i == 0 )
				break ;
		}
		++k;
	}
	return ( order );
}

std::vector< int > PmergeMe::mergeVector( const std::vector< int > &vec ) {
	size_t n = vec.size();
	if (n <= 1) {
		return vec;
	}

	bool hasAlone = false;
	int alone = 0;
	size_t limit = (n / 2) * 2;

	if ( n % 2 != 0 ) {
		hasAlone = true;
		alone = vec[ n - 1 ];
	}

	std::vector< std::pair< int, int > > pairs;
	for ( size_t i = 0; i < limit; i += 2 ) {
		int a = vec[ i ];
		int b = vec[ i + 1 ];
		if ( a > b )
			std::swap( a, b );
		pairs.push_back( std::make_pair( a, b ) );
	}

	std::vector< int > main;

	for ( size_t i = 0; i < pairs.size(); ++i )
		main.push_back( pairs[ i ].second );

	main = mergeVector( main );

	std::vector< int > pend;
	for ( size_t i = 0; i < pairs.size(); ++i )
		pend.push_back( pairs[ i ].first );

	std::cout << "Main: ";
	for ( size_t i = 0; i < main.size(); i++ ) {
		std::cout << main[ i ] << ", ";
	}
	std::cout << LEND << "Pend: ";
	for ( size_t i = 0; i < pend.size(); i++ ) {
		std::cout << pend[ i ] << ", ";
	}
	std::cout << LEND << LEND;

	std::vector< size_t > order = insert( pend.size() );

	for ( size_t idx = 0; idx < order.size(); ++idx ) {
		if ( order[ idx ] >= pend.size() )
			continue ;
		int valueToInsert = pend[ order[ idx ] ];
		std::vector< int >::iterator it = std::lower_bound( main.begin(), main.end(), valueToInsert );
		main.insert( it, valueToInsert );
	}

	if ( hasAlone ) {
		std::vector< int >::iterator it = std::lower_bound( main.begin(), main.end(), alone );
		main.insert( it, alone );
	}

	return ( main );
}

std::list< int > PmergeMe::mergeList( const std::list< int > &lst ) {
	std::list< int > work = lst;
	size_t n = work.size();
	if ( n <= 1 )
		return ( work );

	bool hasAlone = false;
	int alone = 0;
	if ( n % 2 != 0 ) {
		hasAlone = true;
		alone = work.back();
		work.pop_back();
	}

	std::list< int > mains;
	std::list< int > pend;

	std::list< int >::iterator it = work.begin();
	while ( it != work.end() ) {
		std::list< int >::iterator it1 = it++;

		if ( it == work.end() )
			break;

		std::list< int >::iterator it2 = it++;

		int a = *it1;
		int b = *it2;
		if ( a <= b ) {
			pend.push_back( a );
			mains.push_back( b );
		} else {
			pend.push_back( b );
			mains.push_back( a );
		}
	}

	mains = mergeList( mains );

	std::vector< size_t > order = insert( pend.size() );

	for ( size_t idx = 0; idx < order.size(); ++idx ) {
		if ( order[ idx ] >= pend.size() )
			continue ;

		std::list< int >::iterator it = pend.begin();
		std::advance( it, order[ idx ] );

		int valueToInsert = *it;

		std::list< int >::iterator pos = mains.begin();

		while ( pos != mains.end() && *pos < valueToInsert )
			++pos;
		mains.insert( pos, valueToInsert );
	}

	if ( hasAlone ) {
		std::list< int >::iterator pos = mains.begin();
		while ( pos != mains.end() && *pos < alone )
			++pos;
		mains.insert(pos, alone);
	}

	return ( mains );
}

double	PmergeMe::getElapsedTime( const std::string &containerType ) const {
	if ( containerType == "vector" ) {
		return ( this->_elapsedVector );
	} else if ( containerType == "list" ) {
		return ( this->_elapsedList );
	}
	return ( -1 );
}


void PmergeMe::run( std::vector< int > &data ) {
	clock_t start = clock();
	data = mergeVector( data );
	clock_t end = clock();
	_elapsedVector = ( double )( end - start ) * 1000000.0 / CLOCKS_PER_SEC;
}


void PmergeMe::run( std::list< int > &data ) {
	clock_t start = clock();
	data = mergeList( data );
	clock_t end = clock();
	_elapsedList = ( double )( end - start ) * 1000000.0 / CLOCKS_PER_SEC;
}

