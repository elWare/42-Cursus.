/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:26:43 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/21 11:54:33 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int     main(void) {

        std::cout << std::endl;

        std::string str = "HI THIS IS BRAIN";
        std::string *stringPTR = &str;
        std::string &stringREF = str;

        std::cout << "🧠 Variable, puntero y referencia inicializada 🧠" << std::endl;

        std::cout << std::endl;
        std::cout << "🧠 Imprimiendo direcciones de memoria 🧠" << std::endl;
        std::cout << std::endl;

        std::cout << "Direccion de la variable string (&str): " << &str << std::endl;
        std::cout << "Dirección que contiene el puntero stringPTR (stringPTR):" << stringPTR << std::endl;
        std::cout << "Dirección que contiene la referencia (&stringREF):" << &stringREF << std::endl;

        std::cout << std::endl;
        std::cout << "🧠 Imprimiendo valores🧠" << std::endl;
        std::cout << std::endl;

        std::cout << "Valor de la varible string (str): " << str << std::endl;
        std::cout << "Valor que apunta el puntero (*stringPTR): " << *stringPTR << std::endl;
        std::cout << "Valor que apunta la referencia (stringREF): " << stringREF << std::endl;

        std::cout << std::endl;

        return (0);
}
