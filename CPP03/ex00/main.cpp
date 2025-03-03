#include "ClapTrap.hpp"
#include "ClapTrap.h"

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
	return (0);
}