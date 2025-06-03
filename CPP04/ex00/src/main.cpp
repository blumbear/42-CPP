#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::cout << "test from subject" <<std::endl;
	std::cout << "-----" << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const WrongAnimal* i = new WrongCat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl;

	std::cout << "Other test" <<std::endl;
	std::cout << "-----" << std::endl;

	const Animal* dog = new Dog();
	const WrongAnimal* cat = new WrongCat();

	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound(); //will output the cat sound!
	dog->makeSound(); //will output the cat sound!
	std::cout << dog->getType() << " " << std::endl;
	std::cout << std::endl;

	std::cout << "Destructor" <<std::endl;
	std::cout << "-----" << std::endl;

	delete meta;
	delete i;
	delete j;
	delete dog;
	delete cat;
	return 0;
}