#include "ClapTrap.hpp"
#include "ClapTrap.h"
#include "ScavTrap.hpp"
#include "ScavTrap.h"

int main( void )
{
	ClapTrap A=ClapTrap();
	ClapTrap B=ClapTrap("Beta");

	A.setName("Alpha");
	A.attack(B.getName());
	B.takeDamage(A.getAttack());
	A.setAttack(10);
	A.attack(B.getName());
	B.takeDamage(A.getAttack());
	A.attack(B.getName());
	B.takeDamage(A.getAttack());
	B.attack(A.getName());

	std::cout << "---------------------" << std::endl;

	ScavTrap C=ScavTrap("Charlie");
	C.guardGate();
	A.attack(C.getName());
	C.takeDamage(A.getAttack());
	C.attack(A.getName());
	A.takeDamage(C.getAttack());
	A.attack(C.getName());
	return (0);
}