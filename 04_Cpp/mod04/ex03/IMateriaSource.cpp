/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 18:48:59 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/19 18:49:05 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
// No es necesario incluir iostream si no hay salida en el destructor.

// Definición fuera de línea del destructor virtual.
// Es importante que tenga una definición, aunque esté vacío.
IMateriaSource::~IMateriaSource() {
    // Opcional: std::cout << "IMateriaSource destructor called." << std::endl;
}