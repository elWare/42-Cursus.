/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 18:29:56 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/27 09:54:15 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp" // También incluimos WrongCat, que a su vez incluye WrongAnimal

using std::cout;
using std::endl;

int main()
{
	// Sección 1: Demostración de polimorfismo con Animal, Dog y Cat
	const Animal* meta = new Animal(); // Objeto Animal base
	const Animal* j = new Dog();       // Puntero a Animal que apunta a un Dog
	const Animal* i = new Cat();       // Puntero a Animal que apunta a un Cat

	cout << "\n* * * * * * * Animals * * * * * * * " << endl;

	cout << endl;
	cout << "New type: " << j->getType() << endl; // Muestra el tipo "Dog"
	cout << "New Type: " << i->getType() << endl; // Muestra el tipo "Cat"

	cout << "\n* * * * * Animals sounds  * * * * * " << endl;
	cout << endl;
	i->makeSound(); 			// Llamará a Cat::makeSound() (Output: Meow meow 🔊)
	j->makeSound();				// Llamará a Dog::makeSound() (Output: Woof woof 🔊)
	meta->makeSound();			// Llamará a Animal::makeSound() (Output: Animal sound 🔊)

	cout << "\n* * * * Destroying animals  * * * * " << endl;
	cout << endl;
	delete meta; // Llama a ~Animal()
	delete j;    // Llama a ~Dog() y luego a ~Animal() gracias al destructor virtual
	delete i;    // Llama a ~Cat() y luego a ~Animal() gracias al destructor virtual

	// Sección 2: Demostración de la falta de polimorfismo con WrongAnimal y WrongCat
	cout << "\n* * * * * Testing animals * * * * * " << endl;
	cout << endl;
	WrongAnimal	*wrongAnimal = new WrongAnimal; // Objeto WrongAnimal base
	WrongAnimal	*wrongCat = new WrongCat;       // Puntero a WrongAnimal que apunta a un WrongCat

	cout << "\n* * * wrongAnimal : ";
	wrongAnimal->makeSound(); // Llamará a WrongAnimal::makeSound() (Output: WrongAnimal sound 🐓)
	
	cout << "\n* * * wrongCat    : ";
	wrongCat->makeSound();    // ¡ATENCIÓN! Llamará a WrongAnimal::makeSound() (Output: WrongAnimal sound 🐓) [1]

	cout << "\n* * * Destroying wrong animals * * * " << endl;
	cout << endl;
	delete wrongAnimal; // Llama a ~WrongAnimal()
	delete wrongCat;    // Llama a ~WrongAnimal() (¡No llama a ~WrongCat()!) [1]
}