/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:54:50 by halvarez          #+#    #+#             */
/*   Updated: 2023/05/19 16:19:30 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <sys/epoll.h>

# include "../../include/webserv.hpp"
#include "../config/Config.hpp"
#include "../http/response/Response.hpp"
#include "Server.hpp"


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
		void							str2upload( const int & socket, std::string & str );

		// Setters -------------------------------------------------------------
		bool							setSocket( const int & socket );
		void							setFlag( const int & socket, const int flag );
		void							unSetFlag( const int & socket, const int flag );
		void							setClassResponse( const int & socket, Config & conf, Request & req );

		// Getters -------------------------------------------------------------
		const int					&	getEpollFd( void )				const;
		size_t							size( void )					const;
		const int					&	getPort( const int & socket )	const;
		const std::string			&	getName( const int & socket )	const;
		const int					&	getFlag( const int & socket )	const;
		Response					&	getClassResponse( const int & socket);
		std::vector<unsigned char>	&	getUpload( const int & socker );

	private:
		// Private attributes --------------------------------------------------
		const int										_eplfd;
		std::vector	< int							>	_socket;
		std::map	< int, int						>	_port;
		std::map	< int, std::string				>	_name;
		std::map	< int, int						>	_flag;
		std::map	< int, Response					>	_Response;
		std::map	< int, std::vector< ustring	>	>	_buffer;
		std::map	< int, std::vector<unsigned char>>	_upload;

		// Private functions ---------------------------------------------------
										Client( void );

};

#endif
