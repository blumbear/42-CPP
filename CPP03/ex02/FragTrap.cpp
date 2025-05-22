#include "FragTrap.hpp"
#include "FragTrap.h"

/* ================= Constructor & Destructor ================= */

FragTrap::FragTrap() : ClapTrap(), Name("Default"), HitPoint(100), EnergyPoint(100), AttackDamage(30)
{
	std::cout << FRG_DFLT_CONSTRUCTOR_ANC << std::endl;
}

FragTrap::FragTrap(std::string Name)  : ClapTrap(Name), Name(Name), HitPoint(100), EnergyPoint(100), AttackDamage(30)
{
	std::cout << FRG_NAME_CONSTRUCTOR_ANC << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << FRG_CPY_CONSTRUCTOR_ANC << std::endl;
	*this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << FRG_CPY_ASSIGNEMENT_ANC << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << FRG_DESTRUCTOR_ANC << std::endl;
}


/* ========================= Setter ========================= */

void FragTrap::setName(std::string Name)
{
	this->Name = Name;	
}

void FragTrap::setHealth(int HitPoint)
{
	this->HitPoint = HitPoint;	
}

void FragTrap::setEnergy(int EnergyPoint)
{
	this->EnergyPoint = EnergyPoint;	
}

void FragTrap::setAttack(int AttackDamage)
{
	this->AttackDamage = AttackDamage;	
}


/* ========================= Getter ========================= */

std::string FragTrap::getName( void )
{
	return (this->Name);
}

int FragTrap::getHealth( void )
{
	return (this->HitPoint);
}

int FragTrap::getEnergy( void )
{
	return (this->EnergyPoint);
}

int FragTrap::getAttack( void )
{
	return (this->AttackDamage);
}

/* ========================== Else ========================== */

void FragTrap::attack(const std::string& target)
{
	if (this->HitPoint <= 0)
	{
		std::cout << FRG_DEAD_CANT_ATTACK << std::endl;
		return ;
	}
	else if (this->EnergyPoint <= 0)
	{
		std::cout << FRG_ENERGY_CANT_ATTACK << std::endl;
		return ;
	}
	std::cout << "FragTrap "
			<< this->Name
			<< " attacks "
			<< target
			<< ", causing "
			<< this->AttackDamage
			<< " point of damage!" << std::endl;
	this->EnergyPoint -= 1;
}

void FragTrap::takeDamage(unsigned int amount)
{
	if (HitPoint <= 0)
	{
		std::cout <<FRG_ALREADY_DEAD << std::endl;
		return ;
	}
	this->HitPoint -= amount;
	if (HitPoint <= 0)
		std::cout << "FragTrap " << this->Name << IS_DEAD << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
	std::cout << FRG_REPARATION << std::endl;
	this->HitPoint += amount;
}

void FragTrap::highFivesGuys(void)
{
	if (this->HitPoint <= 0)
		std::cout << FRG_DEAD_HIGH_FIVE << std::endl;
	else if (this->EnergyPoint <= 0)
		std::cout << FRG_ENERGY_HIGH_FIVE << std::endl;
	else
		std::cout << FRG_HIGH_FIVE << std::endl;
	return ;
}

