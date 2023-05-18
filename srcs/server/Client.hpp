/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:54:50 by halvarez          #+#    #+#             */
/*   Updated: 2023/05/18 11:37:15 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <sys/epoll.h>

#include "../config/Config.hpp"
#include "../http/response/Response.hpp"
#include "Server.hpp"

typedef enum e_flag
{
	EMPTY	= 0,
	ERROR	= 1 << 0,
	CONTENT	= 1 << 1
}			t_flag;

class Client
{
	public:
		typedef std::basic_string<unsigned char> ustring;

		// Constructor ---------------------------------------------------------
										Client( const int & eplfd );
		// Destructor ----------------------------------------------------------
										~Client( void );

		// Socket management ---------------------------------------------------
		int								find( const int & socket ) const;
		bool							add( const int & socket, const int & port, const std::string & name );
		void							remove( int & socket );
		
		// Response management -------------------------------------------------
		void							newResponse( const int & socket, std::string res );
		ustring 						getResponse( const int & socket );
		size_t							responseSize( const int & socket )	const;

		// Setters -------------------------------------------------------------
		bool							setSocket( const int & socket );
		void							setFlag( const int & socket, const int flag );

		// Getters -------------------------------------------------------------
		const int					&	getEpollFd( void )				const;
		size_t							size( void )					const;
		const int					&	getPort( const int & socket )	const;
		const std::string			&	getName( const int & socket )	const;
		const int					&	getFlag( const int & socket )	const;

	private:
		// Private attributes --------------------------------------------------
		const int										_eplfd;
		std::vector	< int							>	_socket;
		std::map	< int, int						>	_port;
		std::map	< int, std::string				>	_name;
		std::map	< int, int						>	_flag;
		std::map	< int, std::vector< ustring	>	>	_buffer;

		// Private functions ---------------------------------------------------
										Client( void );

};

#endif
