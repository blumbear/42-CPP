#pragma once

#include "WrongAnimal.hpp"
#include "Animal.h"
#include <string>
#include <iostream>

class WrongCat : public WrongAnimal {
	public :
/* ================= Constructor & Destructor ================= */

		WrongCat();
		WrongCat(const WrongCat &other);
		~WrongCat();

/* ========================= Else ========================= */

		void makeSound() const;
};