/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 13:39:24 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/09 13:40:35 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

using std::cout;
using std::endl;

int main()
{

	DiamondTrap	Diamond("Damien");

	cout << "\n * * * * * * DiamondTrap Damien * * * * * * " << endl;
	
	cout << endl;
	
	Diamond.attack("The priest");			// "Damien" attacks "The priest" [4]
	Diamond.attack("The photographer");		// "Damien" attacks "The photographer" [4]
	Diamond.attack("The mother");			// "Damien" attacks "The mother" [4]

	cout << endl;

	Diamond.beRepaired(6);					// "Damien" is repaired by 6 points [4]
	Diamond.takeDamage(66);					// "Damien" takes 66 points of damage [4]
	Diamond.whoAmI();						// "Damien" is also known as "The child" [4]
	Diamond.highFivesGuys();				// "Damien" says: Give me five! [4]
	Diamond.guardGate();					// "Damien" enters in Gate Keeper Mode [4]

	cout << "\n* * * * * * to be continued * * * * * * " << endl << endl;

	return 0;
}