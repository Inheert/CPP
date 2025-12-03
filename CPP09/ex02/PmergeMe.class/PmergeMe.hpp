/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:22:04 by tclaereb          #+#    #+#             */
/*   Updated: 2025/12/03 11:17:01 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <climits>
#include <cstdlib>
#include <cmath>
#include <algorithm>

class PmergeMe {
	private:
		std::vector< int >	_vectorData;
		std::list< int >	_listData;

		double				_elapsedVector;
		double				_elapsedList;

		std::vector< long >	_jacobstahlVector;
		std::list< long >	_jacobstahlList;

		void					jacobstahlList( void );
		void					jacobstahlVector( void );

		std::vector< int >		mergeVector( const std::vector< int > &vec );
		std::list< int >		mergeList( const std::list< int > &lst);
		std::vector< size_t >	insertVector( size_t pendSize );
		std::vector< size_t >	insertList( size_t pendSize );

	public:
		PmergeMe( void );
		~PmergeMe( void );
		PmergeMe( const PmergeMe &other );
		PmergeMe&	operator=( const PmergeMe &other );

		double		getVectorTime( void ) const;
		double		getListTime( void ) const;

		void		run( std::vector< int > &data );
		void		run( std::list< int > &data );
};
