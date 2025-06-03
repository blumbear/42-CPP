#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main(void)
{
	std::cout << "test from subject" <<std::endl;
	std::cout << "-----" << std::endl;

	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	std::cout << std::endl;

	std::cout << "Other test" <<std::endl;
	std::cout << "-----" << std::endl;

	Dog basic;{Dog tmp = basic;}
	std::cout << std::endl;

	const Animal* dog = new Dog();
	const WrongAnimal* wrongcat = new WrongCat();

	std::cout << wrongcat->getType() << " " << std::endl;
	wrongcat->makeSound(); //will output the wrongcat sound!
	dog->makeSound(); //will output the dog sound!
	std::cout << dog->getType() << " " << std::endl;
	std::cout << std::endl;
	std::cout << "Destructor" <<std::endl;
	std::cout << "-----" << std::endl;

	delete wrongcat;
	delete i;
	delete j;
	delete dog;
	std::cout << std::endl;

	std::cout << "Tab test" <<std::endl;
	std::cout << "-----" << std::endl;

	const Animal* tab[10];
	for (int i = 0; i < 10; i++)
	{
		if (i < 5)
			tab[i] = new Dog();
		else 
			tab[i] = new Cat();
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Tab test Destructor" <<std::endl;
	std::cout << "-----" << std::endl;

	for (int i = 0; i < 10 ; i++)
	{
		delete tab[i];
		std::cout << std::endl;
	}

	return 0;
}