/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 09:19:58 by jumarque          #+#    #+#             */
/*   Updated: 2025/09/29 09:28:56 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	std::cout << "--- Inicio del Programa Zombis ---" << std::endl;

	// --- Demostración de Zombie en la pila (Stack) ---
	std::cout << "\n[1] Creando un Zombie en la pila (Stack) con randomChump:" << std::endl;
	randomChump("ChumpStack"); // El zombie se crea, anuncia y se destruye al final de la función

	std::cout << "[1] randomChump ha terminado. El Zombie de la pila ya no existe." << std::endl;

	// --- Demostración de Zombie en el montón (Heap) ---
	std::cout << "\n[2] Creando un Zombie en el montón (Heap) con newZombie:" << std::endl;
	Zombie* heapZombie1 = newZombie("HeapZombie1"); // Crea un Zombie en el heap, devuelve un puntero
	heapZombie1->announce(); // El Zombie del heap anuncia su presencia

	Zombie* heapZombie2 = newZombie("HeapZombie2"); // Otro Zombie en el heap
	heapZombie2->announce();

	std::cout << "[2] Los Zombis del heap aún existen, ¡es necesario liberarlos manualmente!" << std::endl;

	// ¡CRUCIAL! Liberar la memoria de los Zombis creados en el heap
	std::cout << "[2] Liberando HeapZombie1:" << std::endl;
	delete heapZombie1; // Llama al destructor de HeapZombie1 y libera su memoria

	std::cout << "[2] Liberando HeapZombie2:" << std::endl;
	delete heapZombie2; // Llama al destructor de HeapZombie2 y libera su memoria

	std::cout << "\n--- Fin del Programa Zombis ---" << std::endl;
	return 0;
}