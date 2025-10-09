/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:59:00 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/06 18:00:11 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

using std::cout;
using std::endl;

int main(){

	ScavTrap tmp("Damien");
	ScavTrap Damien("El niño");

	tmp.setEnergyPoints(666);
	Damien = tmp;

	cout << "\n * * * * * * ScavTrap Damien * * * * * * " << endl;
	cout << "\n\tDaño de ataque : " << Damien.getAttackDemage(); // Obtiene el daño de ataque de "Damien"
	cout << "\n\tPuntos de energía : " << Damien.getEnergyPoints(); // Obtiene la energía de "Damien"
	cout << "\n\tPuntos de vida    : " << Damien.getHitPoints() << endl; // Obtiene los puntos de vida de "Damien"

	cout << "\n * * * * * *  Los juegos de Damien  * * * * * * " << endl << endl;

	Damien.attack("El hospital");			// "Damien" ataca "El hospital"
	cout << endl;
	Damien.attack("La niñera");				// "Damien" ataca "La niñera"

	cout << endl;

	Damien.takeDamage(6);					// "Damien" recibe 6 puntos de daño
	Damien.takeDamage(6);					// "Damien" recibe 6 puntos de daño
	Damien.beRepaired(6);					// "Damien" es reparado por 6 puntos

	cout << endl;

	Damien.attack("El cura");				// "Damien" ataca "El cura"
	cout << endl;
	Damien.attack("El fotografo");			// "Damien" ataca "El fotografo"
	cout << endl;
	Damien.attack("La madre");				// "Damien" ataca "La madre"
	cout << endl;
	Damien.attack("El embajador");			// "Damien" ataca "El embajador"

	cout << endl;

	cout << "\n * * * * * * The Omen to be continued... * * * * * * " << endl << endl;
	Damien.guardGate();						// "Damien" entra en Modo Guardián de la Puerta
	cout << "... Y Damien ahora estará bajo la tutela del Presidente..." << endl << endl;

	return 0; // Añadido return 0 para un main válido
}