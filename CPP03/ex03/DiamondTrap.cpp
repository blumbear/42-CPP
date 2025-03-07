#include "DiamondTrap.hpp"
#include "DiamondTrap.h"

/* ================= Constructor & Destructor ================= */

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), name("Default")
{
	std::cout << DMD_DFLT_CONSTRUCTOR_ANC << std::endl;
	this->HitPoint = FragTrap::getAttack();
	this->EnergyPoint = ScavTrap::getEnergy();
	this->AttackDamage = FragTrap::getAttack();
}

DiamondTrap::DiamondTrap(std::string Name) ClapTrap(Name + "_clap_name"), name(Name)
{
	std::cout << DMD_NAME_CONSTRUCTOR_ANC << std::endl;
	this->HitPoint = FragTrap::getAttack();
	this->EnergyPoint = ScavTrap::getEnergy();
	this->AttackDamage = FragTrap::getAttack();
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	std::cout << DMD_CPY_CONSTRUCTOR_ANC << std::endl;
	this->attackDamage = DiamondTrap.attackDamage;
	this->energyPoints = DiamondTrap.energyPoints;
	this->hitPoints = DiamondTrap.hitPoints;
	this->name = DiamondTrap.name;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << DMD_DESTRUCTOR_ANC << std::endl;
}

/* ========================== Else ========================== */

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack();
}

void DiamondTrap::takeDamage(unsigned int amount)
{
	if (HitPoint <= 0)
	{
		std::cout << DMD_ALREADY_DEAD << std::endl;
		return ;
	}
	this->HitPoint -= amount;
	if (HitPoint <= 0)
		std::cout << "DiamondTrap " << this->Name << IS_DEAD << std::endl;
}

void DiamondTrap::beRepaired(unsigned int amount)
{
	std::cout << DMD_REPARATION << std::endl;
	this->HitPoint += amount;
}

void DiamondTrap::whoAmI()
{
	std::cout << "My name is :" << this->name << "and my Claptrap's parent name is :" << ClapTrap::getName() << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &DiamondTrap)
{
	std::cout << "DiamondTrap assignment operator has been called" << std::endl;
	this->attackDamage = DiamondTrap.attackDamage;
	this->energyPoints = DiamondTrap.energyPoints;
	this->hitPoints = DiamondTrap.hitPoints;
	this->name = DiamondTrap.name;
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const DiamondTrap &DiamondTrap)
{
	out << "DiamondTrap " << DiamondTrap.getName()
		<< " now have " << DiamondTrap.getHitPoints()
		<< " hit points, " << DiamondTrap.getEnergyPoints()
		<< " energy points and " << DiamondTrap.getAttackDamage()
		<< " attack damage" << std::endl;
	return (out);
}