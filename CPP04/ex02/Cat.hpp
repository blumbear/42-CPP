#pragma once

#include "Animal.hpp"
#include "Animal.h"
#include "Brain.hpp"
#include <string>
#include <iostream>

class Cat : public Animal {
	private :
		Brain* brain;
	public :
/* ================= Constructor & Destructor ================= */

		Cat();
		Cat(const Cat &other);
		~Cat();

/* ========================= Else ========================= */

		void makeSound() const;
};