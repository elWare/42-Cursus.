/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 11:27:24 by jumarque          #+#    #+#             */
/*   Updated: 2025/09/26 13:31:14 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"
# include <limits>
# include <iomanip>
# include <sstream>

class PhoneBook
{
private:
	Contact contacts[8];
	int num_contacts;
	int next_index;
public:
	PhoneBook();
	~PhoneBook();
	
	void	add_contact();
	void	search_contact() const;
};

#endif