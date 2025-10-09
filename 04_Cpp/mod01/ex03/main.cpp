/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:39:19 by jumarque          #+#    #+#             */
/*   Updated: 2025/09/30 13:16:59 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>

int main() {
    std::cout << "--- Inicio del Programa 'Unnecessary Violence' ---" << std::endl;

    // --- ESCENARIO 1: HumanA (siempre con arma, referencia) ---
    std::cout << "\n--- Escenario 1: HumanA ---" << std::endl;
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("new shiny axe");
        bob.attack();
    }
    // --- ESCENARIO 2: HumanB (puede no tener arma, usa puntero) ---
    std::cout << "\n--- Escenario 2: HumanB ---" << std::endl;
    {
        Weapon pistol = Weapon("heavy pistol");
        HumanB jim("Jim");
        jim.attack();

        jim.setWeapon(pistol);
        jim.attack();

        pistol.setType("light machine gun");
        jim.attack();
        // Podemos crear otra arma y Jim puede cambiarla
        Weapon knife = Weapon("sharp knife");
        jim.setWeapon(knife);
        jim.attack();
    }
    // --- ESCENARIO 3: HumanB con arma en el heap ---
    std::cout << "\n--- Escenario 3: HumanB con arma en el HEAP ---" << std::endl;
    {
        Weapon *bow = new Weapon("compound bow");
        HumanB kevin("Kevin");
        kevin.setWeapon(*bow);
        kevin.attack();
        
        bow->setType("laser cannon"); 
        kevin.attack();

        delete bow; // ¡IMPORTANTE! Liberar el arma del HEAP
    }
    std::cout << "\n--- Fin del Programa 'Unnecessary Violence' ---" << std::endl;
    return 0;
}
/* Main subject
int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
return 0;
}
*/