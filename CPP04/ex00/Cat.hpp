#pragma once

#include "Animal.hpp"
#include "Animal.h"
#include <string>
#include <iostream>

class Cat : public Animal {
	public :
/* ================= Constructor & Destructor ================= */

		Cat();
		Cat(const Cat &other);
		~Cat();

/* ========================= Else ========================= */

		void makeSound() const;
};