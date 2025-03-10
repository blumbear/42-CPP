#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Animal* animaltab[10];

	for (int i = 0; i < 10; i++)
	{
		if (i <=4)
			animaltab[i] = new Dog();
		else
			animaltab[i] = new Cat();
	} 
	for (int i = 0; i < 10; i++)
	{
		delete animaltab[i];
	} 
	return 0;
}