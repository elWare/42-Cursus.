/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 12:46:13 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/04 12:55:56 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp" // Necesario para la clase Point
#include <iostream>  // Para std::cout, std::endl
#include <string>    // Para std::string

using std::cout; // para evitar std::cout repetitivo

// Declaración de la función bsp (definida en bsp.cpp)
bool bsp(const Point& a, const Point& b, const Point& c, const Point& point);

// Función auxiliar para imprimir texto en verde
static void printGreen(const std::string& text) {
	cout << "\033[32m" << text << "\033[0m";
}

// Función auxiliar para imprimir los datos de los puntos
static void	printData(const Point& A, const Point& B, const Point& C, const Point& P){
	cout << "\nThe ";
	printGreen("triangle vertices");
	cout << " are : \n" << std::endl;
	cout << "	position of A : (" << A.getX().toFloat() << ", " << A.getY().toFloat() << ") \n ";
	cout << "	position of B : (" << B.getX().toFloat() << ", " << B.getY().toFloat() << ") \n ";
	cout << "	position of C : (" << C.getX().toFloat() << ", " << C.getY().toFloat() << ")";
	cout << "\n" <<std::endl;
	cout << "The position to search for is (P) : ";
	cout << "(" << P.getX().toFloat() << ", " << P.getY().toFloat() << ")\n" << std::endl;
}

int main( void ) {
	Point		A(0.f, 0.f);
	Point		B(10.f, 30.f);
	Point		C(20.f, 0.f);
	Point		P(0.f, 15.f);	// Punto fuera del triángulo
	//Point		P(10.f, 15.f);	// Punto dentro del triángulo
	std::string	answer;

	if (bsp(A,B,C,P))
		answer = "\033[32m inside \033[0m";
	else
		answer = "\033[31m outside \033[0m";
	printData(A, B, C, P);
	cout << "The point (P) is" << answer << "of the triangle. \n" << std::endl;

	return 0;
}