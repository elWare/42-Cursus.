/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 18:20:01 by jumarque          #+#    #+#             */
/*   Updated: 2025/09/26 17:31:14 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include "phonebook.hpp"

int	main()
{
	PhoneBook myPhoneBook;
	std::string command;
	
	/*#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif*/

	//std::cout << "\033[2J\033[H";
	std::cout << "Bienvenido a My Awesome PhoneBook!" << std::endl;

	while (true) 
	{
		std::cout << "\nIntroduce un comando (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);

		if (std::cin.eof())
		{
			std::cout << "\nEOF detectado. Saliendo del programa." << std::endl;
			break;
		}
		std::transform(command.begin(), command.end(), command.begin(), ::toupper);
		command.erase(std::remove_if(command.begin(), command.end(), ::isspace), command.end());

		if (command == "ADD")
		{
			myPhoneBook.add_contact();
		}
		else if (command == "SEARCH")
		{
			myPhoneBook.search_contact(); // Llama al método de búsqueda (pendiente) [1]
		}
		else if (command == "EXIT")
		{
			std::cout << "Saliendo de la agenda. ¡Adiós!" << std::endl;
			break;
		}
		else
		{
			std::cout << "Comando inválido. Por favor, usa ADD, SEARCH o EXIT." << std::endl;
		}
	}
	return (0);
}