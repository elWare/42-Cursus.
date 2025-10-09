/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 09:19:58 by jumarque          #+#    #+#             */
/*   Updated: 2025/09/29 10:06:14 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main()
{
	std::cout << "--- Inicio del Programa Horda de Zombis ---" << std::endl;

	// --- PRUEBA 1: Crear una horda de 5 zombis ---
	std::cout << "\n[1] Creando una horda de 5 zombis con nombre 'HordaMain':" << std::endl;
	Zombie* myHorde = zombieHorde(5, "HordaMain");

	if (myHorde)
	{
		for (int i = 0; i < 5; ++i) {
			myHorde[i].announce();
		}

		std::cout << "[1] La horda de zombis ha sido creada. ¡Ahora a liberarla!" << std::endl;
		delete[] myHorde; 
		std::cout << "[1] La horda de zombis ha sido liberada." << std::endl;
	}
	else
	{
		std::cout << "[1] Fallo al crear la horda." << std::endl;
	}

	// --- PRUEBA 2: Intentar crear una horda con un número inválido ---
	std::cout << "\n[2] Intentando crear una horda con 0 zombis:" << std::endl;
	Zombie* emptyHorde = zombieHorde(0, "HordaVacia");
	if (!emptyHorde) {
		std::cout << "[2] Correctamente gestionado: No se creó ninguna horda para N=0." << std::endl;
	} else {
		std::cout << "[2] Error: se creó una horda para N=0. Liberando memoria..." << std::endl;
		delete[] emptyHorde;
	}

	std::cout << "\n--- Fin del Programa Horda de Zombis ---" << std::endl;
	return 0;
}