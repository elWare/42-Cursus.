/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 08:50:12 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/04 12:07:53 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}

//my main tester

/* int main() {
    std::cout << "--- Inicio del Programa Fixed (ex02) ---" << std::endl;
	
	// Ejemplo del subject (implica *, float y int constructors)
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;

    // Pruebas de Operadores de Comparación
    std::cout << "\n--- Pruebas de Comparación ---" << std::endl;
    Fixed c(10);
    Fixed d(10);
    Fixed e(5);

    std::cout << "c: " << c << ", d: " << d << ", e: " << e << std::endl;
    std::cout << "c >= d: " << (c >= d) << std::endl; // Esperado: 1 (true)
    std::cout << "c <= d: " << (c <= d) << std::endl; // Esperado: 1 (true)
    std::cout << "c == d: " << (c == d) << std::endl; // Esperado: 1 (true)
    std::cout << "c > d: " << (c > d) << std::endl; // Esperado: 1 (true)
    std::cout << "c < d: " << (c < d) << std::endl; // Esperado: 1 (true)
    std::cout << "c != d: " << (c != d) << std::endl; // Esperado: 1 (true)

    std::cout << "c >= e: " << (c >= e) << std::endl; // Esperado: 1 (true)
    std::cout << "c <= e: " << (c <= e) << std::endl; // Esperado: 0 (false)
    std::cout << "c == e: " << (c == e) << std::endl; // Esperado: 0 (false)

    // Pruebas de Operadores Aritméticos
    std::cout << "\n--- Pruebas Aritméticas ---" << std::endl;
    Fixed f(5);
    Fixed g(2);
	std::cout << "f: " << f << " g: " << g << std::endl;
    std::cout << "f + g: " << (f + g) << std::endl; // Esperado: 7
    std::cout << "f - g: " << (f - g) << std::endl; // Esperado: 3
    std::cout << "f * g: " << (f * g) << std::endl; // Esperado: 10
    std::cout << "f / g: " << (f / g) << std::endl; // Esperado: 2.5

    // Pruebas de Incremento/Decremento
    std::cout << "\n--- Pruebas de Incremento/Decremento ---" << std::endl;
    Fixed h(10);
    std::cout << "h: " << h++ << std::endl; // Post-incremento
    std::cout << "h: " << h << std::endl;
    std::cout << "h: " << ++h << std::endl; // Pre-incremento
    std::cout << "h: " << h << std::endl;

    // Pruebas de min/max estáticos
    std::cout << "\n--- Pruebas de min/max ---" << std::endl;
    Fixed i(10);
    Fixed j(20);
	std::cout << "i: " << i << " j: " << j << std::endl;
    std::cout << "Min(i, j): " << Fixed::min(i, j) << std::endl; // Esperado: 10
    std::cout << "Max(i, j): " << Fixed::max(i, j) << std::endl; // Esperado: 20

    std::cout << "\n--- Fin del Programa Fixed (ex02) ---" << std::endl;
    return 0;
} */