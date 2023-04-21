/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CGI.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 22:09:47 by auzun             #+#    #+#             */
/*   Updated: 2023/04/21 04:52:50 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CGI_HPP
# define CGI_HPP

# include "../http/request/Request.hpp"
# include <vector>
# include <algorithm>
# include <unistd.h>
# include <string.h>
# include <sys/wait.h>
# include <stdlib.h>

# define	CGI_BUFSIZE 42424

class CGI
{
	public:
		CGI();
		CGI(Request &request);
		~CGI();

		void	setEnv();
		std::string	execCGI(std::string scriptName);
	private:
		Request			_request;

		std::string			_body;
		std::vector<char*>	_args;
		char				**_env;
		char				*_querystring;
};

# endif