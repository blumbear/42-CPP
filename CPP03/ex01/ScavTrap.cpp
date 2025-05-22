#include "ScavTrap.hpp"
#include "ScavTrap.h"

/* ================= Constructor & Destructor ================= */

ScavTrap::ScavTrap() : ClapTrap(), Name("Default"), HitPoint(100), EnergyPoint(50), AttackDamage(20), guard(false)
{
	std::cout << SCV_NAME_CONSTRUCTOR_ANC << std::endl;
}

ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name), Name(Name), HitPoint(100), EnergyPoint(50), AttackDamage(20), guard(false)
{
	std::cout << SCV_NAME_CONSTRUCTOR_ANC << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << SCV_CPY_CONSTRUCTOR_ANC << std::endl;
	*this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << SCV_CPY_ASSIGNEMENT_ANC << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << SCV_DESTRUCTOR_ANC << std::endl;
}

/* ========================= Setter ========================= */

void ScavTrap::setName(std::string Name)
{
	this->Name = Name;
}

void ScavTrap::setHealth(int HitPoint)
{
	this->HitPoint = HitPoint;
}

void ScavTrap::setEnergy(int EnergyPoint)
{
	this->EnergyPoint = EnergyPoint;
}

void ScavTrap::setAttack(int AttackDamage)
{
	this->AttackDamage = AttackDamage;
}


/* ========================= Getter ========================= */

std::string ScavTrap::getName( void )
{
	return (this->Name);
}

int ScavTrap::getHealth( void )
{
	return (this->HitPoint);
}

int ScavTrap::getEnergy( void )
{
	return (this->EnergyPoint);
}

int ScavTrap::getAttack( void )
{
	return (this->AttackDamage);
}


/* ========================== Else ========================== */

void ScavTrap::attack(const std::string& target)
{
	if (this->HitPoint <= 0)
	{
		std::cout << SCV_DEAD_CANT_ATTACK << std::endl;
		return ;
	}
	else if (this->EnergyPoint <= 0)
	{
		std::cout << SCV_ENERGY_CANT_ATTACK << std::endl;
		return ;
	}
	std::cout << "ScavTrap "
			<< this->Name
			<< " attacks "
			<< target
			<< ", causing "
			<< this->AttackDamage
			<< " point of damage!" << std::endl;
	this->EnergyPoint -= 1;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (HitPoint <= 0)
	{
		std::cout << SCV_ALREADY_DEAD << std::endl;
		return ;
	}
	else if (this->guard == true)
	{
		std::cout << SCV_GUARD_GATE_TAKE_DMG << std::endl;
		this->guard = false;
		return ;
	}
	this->HitPoint -= amount;
	if (HitPoint <= 0)
		std::cout << "ScavTrap " << this->Name << IS_DEAD << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	std::cout << SCV_REPARATION << std::endl;
	this->HitPoint += amount;
}

void ScavTrap::guardGate( void )
{
	if (this->HitPoint <= 0)
	{
		std::cout << SCV_DEAD_GUARD_GATE << std::endl;
		return ;
	}
	else if (this->EnergyPoint <= 0)
	{
		std::cout << SCV_ENERGY_GUARD_GATE << std::endl;
		return ;
	}
	this->EnergyPoint -= 1;
	this->guard = true;
	std::cout << SCV_GUARD_GATE << std::endl;
}

