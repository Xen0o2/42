/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:48:57 by alecoutr          #+#    #+#             */
/*   Updated: 2023/07/11 11:16:50 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>

class	Contact
{
	private:
		std::string _firstname;
		std::string _lastname;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;
	public:
		Contact ( void );
		~Contact ( void );

		void	display(int index);
		void	showInformation( void );

		std::string	getFirstname( void );
		void		setFirstname( std::string );
		std::string	getLastname( void );
		void		setLastname( std::string );
		std::string	getNickname( void );
		void		setNickname( std::string );
		std::string	getPhoneNumber( void );
		void		setPhoneNumber( std::string );
		std::string	getDarkestSecret( void );
		void		setDarkestSecret( std::string );
};

#endif
