#include "ClapTrap.hpp"
#include "ClapTrap.h"

/* ================= Constructor & Destructor ================= */

ClapTrap::ClapTrap() : Name("Default"), HitPoint(100), EnergyPoint(50), AttackDamage(20)
{
	std::cout << CLP_DFLT_CONSTRUCTOR_ANC << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : Name(name), HitPoint(100), EnergyPoint(50), AttackDamage(20)
{
 	std::cout << CLP_NAME_CONSTRUCTOR_ANC << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
 	std::cout << CLP_CPY_CONSTRUCTOR_ANC << std::endl;
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << CLP_CPY_ASSIGNEMENT_ANC << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap()
{
 	std::cout << CLP_DESTRUCTOR_ANC << std::endl;
}

/* ========================= Setter ========================= */

void ClapTrap::setName(std::string Name)
{
	if (this->Name != "Default")
		std::cout << CLP_NAME_ALLREADY_SET << std::endl;
	else
		this->Name = Name;
}

void ClapTrap::setHealth(int HitPoint)
{
	this->HitPoint = HitPoint;
}

void ClapTrap::setEnergy(int EnergyPoint)
{
	this->EnergyPoint = EnergyPoint;
}

void ClapTrap::setAttack(int AttackDamage)
{
	this->AttackDamage = AttackDamage;
}

/* ========================= Getter ========================= */

std::string ClapTrap::getName( void )
{
	return (this->Name);
}

int ClapTrap::getHealth( void )
{
	return (this->HitPoint);
}

int ClapTrap::getEnergy( void )
{
	return (this->EnergyPoint); 
}

int ClapTrap::getAttack( void )
{
	return (this->AttackDamage);
}

/* ========================== Else ========================== */

void ClapTrap::attack(const std::string& target)
{
	if (this->HitPoint <= 0)
	{
		std::cout << CLP_DEAD_CANT_ATTACK << std::endl;
		return ;
	}
	else if (this->EnergyPoint <= 0)
	{
		std::cout << CLP_ENERGY_CANT_ATTACK << std::endl;
		return ;
	}
	std::cout << "ClapTrap "
			<< this->Name
			<< " attacks "
			<< target
			<< ", causing "
			<< this->AttackDamage
			<< " point of damage!" << std::endl;
	this->EnergyPoint -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (HitPoint <= 0)
	{
		std::cout << CLP_ALREADY_DEAD << std::endl;
		return ;
	}
	this->HitPoint -= amount;
	if (HitPoint <= 0)
		std::cout << "ClapTrap " << this->Name << IS_DEAD << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << CLP_REPARATION << std::endl;
	this->HitPoint += amount;
}
