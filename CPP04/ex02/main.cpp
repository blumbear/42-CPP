#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongI = new WrongCat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << wrongI->getType() << " " << std::endl;
	wrongI->makeSound(); //will output the cat sound!
	i->makeSound();
	j->makeSound();
	wrongMeta->makeSound();
	
	delete wrongMeta;
	delete i;
	delete wrongI;
	delete j;
	return 0;
}