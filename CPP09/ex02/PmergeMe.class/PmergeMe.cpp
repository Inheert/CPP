/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:22:09 by tclaereb          #+#    #+#             */
/*   Updated: 2025/12/03 11:24:39 by tclaereb         ###   ########.fr       */
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

PmergeMe::PmergeMe( const PmergeMe& other )
	: _vectorData( other._vectorData ),
	_listData( other._listData ),
	_elapsedVector( other._elapsedVector ),
	_elapsedList( other._elapsedList ),
	_jacobstahlVector( other._jacobstahlVector ),
	_jacobstahlList( other._jacobstahlList )
{}

PmergeMe& PmergeMe::operator=( const PmergeMe& other ) {
	if ( this == &other )
		return ( *this );

	_vectorData = other._vectorData;
	_listData = other._listData;
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

std::vector< size_t > PmergeMe::insertVector( size_t pendSize ) {
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

std::vector< size_t > PmergeMe::insertList( size_t pendSize ) {
	return ( insertVector( pendSize ) );
}

std::vector< int > PmergeMe::mergeVector( const std::vector< int > &vec ) {
	size_t limit = vec.size();
	if ( limit <= 1 )
		return ( vec );

	bool hasAlone = false;
	int alone = 0;

	if ( limit % 2 != 0 ) {
		hasAlone = true;
		alone = vec[ limit - 1 ];
	}

	std::vector< std::pair< int, int > > pairs;
	pairs.reserve( limit * 0.5 );
	for ( size_t i = 0; i < limit; i += 2 ) {
		int a = vec[ i ];
		int b = vec[ i + 1 ];
		if ( a > b )
			std::swap( a, b );
		pairs.push_back( std::make_pair( a, b ) );
	}

	std::vector< int > sortedMains;
	sortedMains.reserve( pairs.size() + ( hasAlone ? 1 : 0 ) );

	for ( size_t i = 0; i < pairs.size(); ++i )
		sortedMains.push_back( pairs[ i ].second );

	sortedMains = mergeVector( sortedMains );

	std::vector< int > pendMains;
	pendMains.reserve( pairs.size() );
	for ( size_t i = 0; i < pairs.size(); ++i )
		pendMains.push_back( pairs[ i ].first );

	std::vector< size_t > order = insertVector( pendMains.size() );

	for ( size_t idx = 0; idx < order.size(); ++idx ) {
		if ( order[ idx ] >= pendMains.size() )
			continue ;
		int valueToInsert = pendMains[ order[ idx ] ];
		std::vector< int >::iterator it = std::lower_bound( sortedMains.begin(), sortedMains.end(), valueToInsert );
		sortedMains.insert( it, valueToInsert );
	}

	if ( hasAlone ) {
		std::vector< int >::iterator it = std::lower_bound( sortedMains.begin(), sortedMains.end(), alone );
		sortedMains.insert( it, alone );
	}

	return ( sortedMains );
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
	std::vector< int > pendMains;

	std::list< int >::iterator it = work.begin();
	while ( it != work.end() ) {
		std::list< int >::iterator it1 = it++;

		if ( it == work.end() )
			break;

		std::list< int >::iterator it2 = it++;

		int a = *it1;
		int b = *it2;
		if ( a <= b ) {
			pendMains.push_back( a );
			mains.push_back( b );
		} else {
			pendMains.push_back( b );
			mains.push_back( a );
		}
	}

	mains = mergeList( mains );

	std::vector< size_t > order = insertList( pendMains.size() );

	for ( size_t idx = 0; idx < order.size(); ++idx ) {
		if ( order[ idx ] >= pendMains.size() )
			continue ;
		int valueToInsert = pendMains[ order[ idx ] ];

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

double PmergeMe::getVectorTime() const {
	return ( _elapsedVector );
}

void PmergeMe::run( std::vector< int > &data ) {
	clock_t start = clock();
	_vectorData = mergeVector( data );
	clock_t end = clock();
	_elapsedVector = ( double )( end - start ) * 1000000.0 / CLOCKS_PER_SEC;
	data = _vectorData;
}

double PmergeMe::getListTime() const {
	return ( _elapsedList );
}

void PmergeMe::run( std::list< int > &data ) {
	clock_t start = clock();
	_listData = mergeList( data );
	clock_t end = clock();
	_elapsedList = ( double )( end - start ) * 1000000.0 / CLOCKS_PER_SEC;
	data = _listData;
}

