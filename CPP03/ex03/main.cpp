#include "DiamondTrap.hpp"

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

	std::cout << "---------------------" << std::endl;

	FragTrap D=FragTrap("Delta");
	D.highFivesGuys();
	D.setEnergy(2);
	D.attack(B.getName());
	B.takeDamage(D.getAttack());
	D.attack(B.getName());
	B.takeDamage(D.getAttack());
	D.highFivesGuys();
	A.attack(D.getName());
	D.takeDamage(A.getAttack());
	A.attack(D.getName());
	D.takeDamage(A.getAttack());
	A.attack(D.getName());
	D.takeDamage(A.getAttack());

	std::cout << "---------------------" << std::endl;

	DiamondTrap E=DiamondTrap("Epsilon");
	E.attack(A.getName());
	E.whoAmI();

	return (0);
}