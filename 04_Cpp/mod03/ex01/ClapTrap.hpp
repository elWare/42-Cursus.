/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 10:50:21 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/26 20:36:22 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
protected:
	std::string		_name;
	unsigned int	_energyPoints;
	unsigned int	_hitPoints;
	unsigned int	_attackDemage;
public:
	ClapTrap(void);
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap& newClapTrap);
	~ClapTrap();
	
	ClapTrap& operator=(const ClapTrap& newClapTrap);
	
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	// Setter

	void	setAttackDemage(unsigned int attackDemage);
	void	setHitPoints(unsigned int hitPoints);
	void	setEnergyPoints(unsigned int energyPoints);
	void	setName(std::string name);

	// Getter
	
	unsigned int	getAttackDemage() const;
	unsigned int	getHitPoints() const;
	unsigned int	getEnergyPoints() const;
	const std::string&	getName() const;
};	

#endif