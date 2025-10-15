/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:01:29 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/15 14:31:59 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

using std::cout;
using std::endl;

int main()
{
	cout << "--- Test 1: Intentar instanciar Animal (debería fallar en compilación) ---" << endl;
	// const Animal* abstractAnimal = new Animal(); // Esto NO compilará, Animal es abstracta
	// cout << "Output de la compilacion: error: cannot declare variable 'abstractAnimal' to be of abstract type 'Animal'" << endl;
	cout << "El compilador evitará que instanciemos Animal directamente, ¡correctamente!" << endl;
	cout << "------------------------------------------------------------------" << endl << endl;

	cout << "--- Test 2: Creación y uso básico de Dog y Cat ---" << endl;
	const Animal* myDog = new Dog(); // Puntero a Animal, objeto Dog real
	const Animal* myCat = new Cat(); // Puntero a Animal, objeto Cat real

	cout << "Tipo de myDog: " << myDog->getType() << endl;
	cout << "Sonido de myDog: ";
	myDog->makeSound(); // Polimorfismo: llama a Dog::makeSound()

	cout << "Tipo de myCat: " << myCat->getType() << endl;
	cout << "Sonido de myCat: ";
	myCat->makeSound(); // Polimorfismo: llama a Cat::makeSound()

	cout << "------------------------------------------------------------------" << endl << endl;

	cout << "--- Test 3: Acceso a los Brains y adición de ideas ---" << endl;
	// Es necesario castear para acceder a getBrain(), ya que getBrain() es virtual puro en Animal
	// y para modificar el Brain se necesita un puntero no const al Brain
	Dog* specificDog = dynamic_cast<Dog*>(const_cast<Animal*>(myDog));
	Cat* specificCat = dynamic_cast<Cat*>(const_cast<Animal*>(myCat));

	if (specificDog && specificCat) {
		specificDog->getBrain()->addIdea("Quiero una galleta.");
		specificDog->getBrain()->addIdea("Ladrar al cartero.");
		cout << "Primera idea del perro: " << specificDog->getBrain()->getIdea(0) << endl;

		specificCat->getBrain()->addIdea("Necesito dormir 18 horas.");
		specificCat->getBrain()->addIdea("Ignorar a los humanos.");
		cout << "Primera idea del gato: " << specificCat->getBrain()->getIdea(0) << endl;
	}
	
	cout << "------------------------------------------------------------------" << endl << endl;

	cout << "--- Test 4: Demostración de Copia Profunda (Deep Copy) ---" << endl;
	Dog originalDog; // Crea un perro original con un Brain
	originalDog.getBrain()->addIdea("Soy el perro original.");
	originalDog.getBrain()->addIdea("Jugar a la pelota.");
	cout << "Original Dog primera idea: " << originalDog.getBrain()->getIdea(0) << endl;

	Dog copiedDog = originalDog; // Constructor de copia (Deep Copy)
	cout << "Copied Dog primera idea (antes de cambiar): " << copiedDog.getBrain()->getIdea(0) << endl;
	
	// Cambiamos una idea en el perro copiado
	copiedDog.getBrain()->addIdea("Quiero una chuleta."); // Añadimos una tercera idea al copiado
	// Si el 'Brain' fuera una copia superficial, cambiar una idea en copiedDog afectaría a originalDog.
	// Con copia profunda, son independientes.
	cout << "Original Dog primera idea (despues de cambiar en copia): " << originalDog.getBrain()->getIdea(0) << endl;
	cout << "Copied Dog segunda idea: " << copiedDog.getBrain()->getIdea(1) << endl;
	cout << "Copied Dog tercera idea (añadida despues): " << copiedDog.getBrain()->getIdea(2) << endl;

	cout << "------------------------------------------------------------------" << endl << endl;

	cout << "--- Test 5: Array de Animales (polimorfismo y limpieza) ---" << endl;
	Animal* zoo[4];
	// zoo[0] = new Animal(); // Esto no compilaría
	zoo[0] = new Dog();
	zoo[1] = new Cat();
	zoo[2] = new Dog();
	zoo[3] = new Cat();

	for (int i = 0; i < 4; i++) {
		zoo[i]->makeSound(); // Polimorfismo en acción
	}
	cout << "Eliminando animales del zoo..." << endl;
	for (int i = 0; i < 4; i++) {
		delete zoo[i]; // El destructor virtual asegura la liberación correcta del Brain
	}
	cout << "Animales del zoo eliminados." << endl;
	cout << "------------------------------------------------------------------" << endl << endl;


	cout << "--- Test 6: Limpiando memoria de myDog y myCat ---" << endl;
	delete myDog; // Llama a ~Dog() y luego ~Animal(), liberando el Brain
	delete myCat; // Llama a ~Cat() y luego ~Animal(), liberando el Brain
	cout << "myDog y myCat eliminados correctamente." << endl;
	cout << "------------------------------------------------------------------" << endl << endl;

	return 0;
}