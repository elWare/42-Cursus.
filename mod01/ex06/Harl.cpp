/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:43:56 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/02 09:23:11 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	handlers[0].severity = "DEBUG";
	handlers[0].f = &Harl::debug;
	handlers[1].severity = "INFO";
	handlers[1].f = &Harl::info;
	handlers[2].severity = "WARNING";
	handlers[2].f = &Harl::warning;
	handlers[3].severity = "ERROR";
	handlers[3].f = &Harl::error;
}

Harl::~Harl()
{
	//std::cout << "[Harl] Destructor called" << std::endl;
}

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "Me encanta tener credito extra. ¡Me encanta!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "No puedo creer que agregar credito extra cueste tan poco dinero." << std::endl;
	std::cout << "He estado viniendo aquí durante años y nunca tuve credito extra." << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "Creo que debería tener credito extra. ¿Porque no los pedí?" << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "Esto es inaceptable. ¡Quiero dinero extra AHORA MISMO!" << std::endl;
}

void Harl::complain(std::string severity)
{
	int i;

	i = 0;
	while (i <  4)
	{
		if (this->handlers[i].severity == severity)
			break;
		i++;
	}
	switch (i)
	{
		case 0:
			(this->*handlers[0].f)();
			(this->*handlers[1].f)();
			(this->*handlers[2].f)();
			(this->*handlers[3].f)();
			break;
		case 1:
			(this->*handlers[1].f)();
			(this->*handlers[2].f)();
			(this->*handlers[3].f)();
			break;
		case 2:
			(this->*handlers[2].f)();
			(this->*handlers[3].f)();
			break;
		case 3:
			(this->*handlers[3].f)();
			break;
		default:
			std::cout << ARGC_ERR << std::endl;
			break;
	}
}