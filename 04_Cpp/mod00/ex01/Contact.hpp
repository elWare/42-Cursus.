/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:35:36 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/30 18:25:02 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <cctype>

class Contact{
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _tlfNumber;
		std::string _darkestSecret;

	public:
		Contact();
		~Contact();

		//Coge los datos, no modifican el objeto
		const std::string& getFirstName() const;
		const std::string& getLastName() const;
		const std::string& getNickName() const;
		const std::string& getTlfNumber() const;
		const std::string& getDarkestSecret() const;
		
		// colocar datos modifican el objeto
		void setFirstName(const std::string& firstName);
		void setLastName(const std::string& lasatName);
		void setNickName(const std::string& nickName);
		void setTlfNumber(const std::string& tlfNumber);
		void setDarkestSecret(const std::string& darkestSecret);

		void display_full() const;
};

#endif