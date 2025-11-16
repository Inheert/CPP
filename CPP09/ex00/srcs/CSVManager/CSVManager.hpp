/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CSVManager.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 19:21:51 by tclaereb          #+#    #+#             */
/*   Updated: 2025/11/16 19:24:36 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class CSVManager {
	private:

	public:
		CSVManager( void )
		CSVManager( std::string &filename );
		CSVManager( const CSVManager &other );
		CSVManager	&operator=( const CSVManager &other );
		~CSVManager( void );

		
};
