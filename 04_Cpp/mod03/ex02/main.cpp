/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 12:24:04 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/09 12:24:54 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp" // Incluye la definición de la clase FragTrap (que incluye ClapTrap) [4]

using std::cout;
using std::endl;

int main()
{

	FragTrap tmp("Damien");			// Crea un objeto FragTrap temporal llamado "Damien" [4]
	FragTrap Damien("El niño"); // Crea un FragTrap llamado "El niño" [4]

	tmp.setEnergyPoints(666);		// Establece los puntos de energía del objeto temporal a 666 [4]
	Damien = tmp;					// Asigna el objeto temporal al objeto "El niño" (Damien). Llama a ClapTrap::operator= [4, 17]

	cout << "\n* * * * * * FragTrap Damien * * * * * * " << endl;
	cout << "\n\tAttack damage : " << Damien.getAttackDemage();				// Obtiene el daño de ataque de "Damien" [4]
	cout << "\n\tEnergy points : " << Damien.getEnergyPoints();				// Obtiene la energía de "Damien" [4]
	cout << "\n\tHit points    : " << Damien.getHitPoints() << endl;		// Obtiene los puntos de vida de "Damien" [4]

	cout << "\n* * * * * *  Damien's games * * * * * * " << endl << endl;

	Damien.attack("The hospital");			// "Damien" attacks "The hospital" [4]
	cout << endl;
	Damien.attack("The nanny");				// "Damien" attacks "The nanny"

	cout << endl;

	Damien.takeDamage(6);					// "Damien" recibe 6 puntos de daño [4]
	Damien.takeDamage(66);					// "Damien" recibe 66 puntos de daño [4]
	Damien.beRepaired(666);					// "Damien" es reparado por 666 puntos [4]
	Damien.highFivesGuys();					// "Damien" dice: Give me five! [4]
	cout << endl;

	Damien.attack("The priest");			// "Damien" attacks "Father Brennan" [4]
	cout << endl;
	Damien.attack("The photographer");		// "Damien" attacks "The photographer" [4]
	cout << endl;
	Damien.attack("The mother");			// "Damien" attacks "The mother" [4]
	cout << endl;
	Damien.attack("The ambassador");		// "Damien" attacks "The ambassador" [4]

	cout << endl;

	cout << "\n* * * * * * to be continued * * * * * * " << endl << endl;

	return 0;
}