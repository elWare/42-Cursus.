/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 12:12:36 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/25 17:43:47 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp" // Incluye la definición de la clase ClapTrap [4]

using std::cout; // Para usar cout y endl directamente [4]
using std::endl;

int	main() {

	std::string	name = "Bobby";
	ClapTrap	Bobby(name);

	Bobby.setAttackDemage(2);
	cout << "\n* * * * * Bobby is ready to perform! * * * * *\n" << endl;
	cout << "Hit Points    : " << Bobby.getHitPoints() << endl;
	cout << "Energy Points : " << Bobby.getEnergyPoints() << endl;
	cout << "Attack Damage : " << Bobby.getAttackDemage() << endl;
	cout << "\nStatus        : OK" << endl;

	cout << "\n* * * * * *  Bobby's show begins   * * * * * *\n" << endl;
	Bobby.attack("Peter Pan");		// "Bobby" attacks "Peter Pan" (EP: 10 -> 8)
	Bobby.attack("Bambi");			// "Bobby" attacks "Bambi" (EP: 8 -> 6)

	cout << endl;
	Bobby.takeDamage(4);			// "Bobby" takes 4 points of damage (HP: 10 -> 6)
	Bobby.takeDamage(4);			// "Bobby" takes 4 points of damage (HP: 6 -> 2)

	Bobby.beRepaired(10);			// "Bobby" is repaired for 10 points (HP: 2 -> 12)
	cout << endl;

	Bobby.attack("Pinocho");		// "Bobby" attacks "Pinocho" (EP: 6 -> 4)
	Bobby.attack("Mulan");			// "Bobby" attacks "Mulan" (EP: 4 -> 2)
	Bobby.attack("Tarzan");			// "Bobby" attacks "Tarzan" (EP: 2 -> 0)
	Bobby.attack("Nemo");			// "Bobby" attacks "Nemo" (EP: 0 -> -2, pero la validación detiene)

	cout << "\n* * * * * * * Bobby's show ends  * * * * * * *\n" << endl;
	return (0); // Añadido return 0 para un main válido
}