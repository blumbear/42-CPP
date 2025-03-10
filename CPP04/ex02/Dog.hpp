#pragma once

#include "Animal.hpp"
#include "Brain.hpp"
#include "Animal.h"
#include <string>
#include <iostream>

class Dog : public Animal {
	private :
		Brain* brain;
	public :
/* ================= Constructor & Destructor ================= */

		Dog();
		Dog(const Dog &other);
		~Dog();

/* ========================= Else ========================= */

		void makeSound() const;
};