/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 11:35:42 by jumarque          #+#    #+#             */
/*   Updated: 2025/09/26 18:17:10 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

static void print_formatted_field(const std::string& field)
{
	if (field.length() > 12)
		std::cout << std::right << std::setw(12) << (field.substr(0, 10) + "|");
	else
		std::cout << std::right << std::setw(12) << field + "|";
}

void PhoneBook::search_contact() const 
{
	int			i;
	int			index_to_display;
	std::string	line_input;
	
	if (this->num_contacts == 0)
	{
		std::cout << "La agenda está vacía. Añade contactos primero." << std::endl;
		return;
	}
	std::cout << "--- Contactos en la Agenda ---" << std::endl;
	std::cout << std::right << std::setw(12) << "Indice|";
	std::cout << std::right << std::setw(12) << "Nombre|";
	std::cout << std::right << std::setw(12) << "Apellidos|";
	std::cout << std::right << std::setw(12) << "Nick|" << std::endl;
	std::cout << "------------------------------------------------" << std::endl;

	for (i = 0; i < this->num_contacts; i++)
	{
		std::cout << std::right << std::setw(11) << i << "|";
		print_formatted_field(this->contacts[i].getFirstName());
		print_formatted_field(this->contacts[i].getLastName());
		print_formatted_field(this->contacts[i].getNickName());
		std::cout << std::endl;
	}
	std::cout << "------------------------------------------------" << std::endl;
	
	while (true)
	{
		std::cout << "Introduce el índice del contacto a ver (o cual quier letra para cancelar): ";
		if (!std::getline(std::cin, line_input))
		{
			std::cout << "EOF detectado. Cancelando la búsqueda." << std::endl;
			return;
		}
		if (line_input.empty())
		{
			std::cout << "El campo no puede estar vacío. Por favor, inténtelo de nuevo." << std::endl;
			continue;
		}

		std::stringstream ss(line_input);
		ss >> index_to_display;
		if (ss.fail() || !ss.eof())
		{
			std::cout << "Entrada no numérica. Cancelando búsqueda." << std::endl;
			return;
		}
		
		if (index_to_display >= 0 && index_to_display < num_contacts)
		{
			contacts[index_to_display].display_full();
			return;
		}
		else
		{
			std::cout << "Índice inválido. Por favor, introduce un índice entre 0 y " << num_contacts - 1 << "." << std::endl;
		}
	}
}

static std::string get_non_empty_input(const std::string& prompt)
{
	std::string input;

	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input))
		{
			//Aquí entramos si hemos pulsado Ctrl + D y detecta EOF o '\0'
			std::cout << "\n EOF detectado. Saliendo de la entrada" << std::endl;
			exit(0);
		}

		if (input.empty())
			std::cout << "El campo no puede estar vacío. Por favor, inténtelo de nuevo." << std::endl;
		else
			return input;
	}
}

PhoneBook::PhoneBook() : num_contacts(0), next_index(0)
{
	std::cout << "Agenda telefónica creada. ¿Lista para guardar contactos!" << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "Agenda telefónica destruida. ¡Adios a los contactos!" << std::endl;
}

void PhoneBook::add_contact()
{
	Contact	tmp_contact;

	std::cout << "--- Añadiendo nuevo contacto ---" << std::endl;
	tmp_contact.setFirstName(get_non_empty_input("Primer Nombre: "));
	tmp_contact.setLastName(get_non_empty_input("Apellidos: "));
	tmp_contact.setNickName(get_non_empty_input("Nick: "));
	tmp_contact.setTlfNumber(get_non_empty_input("Número de Tlf: "));
	tmp_contact.setDarkestSecret(get_non_empty_input("Secretos: "));

	this->contacts[next_index] = tmp_contact;
	if (num_contacts < 8)
		num_contacts++;
	next_index = (next_index + 1) % 8;

	std::cout << "Contacto añadido correctamente." << std::endl;
	std::cout << "Total de contactos activos: " << this->num_contacts << std::endl;
}