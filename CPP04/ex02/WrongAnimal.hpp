#pragma once

#include "Animal.h" 
#include <string>
#include <iostream>

class WrongAnimal {
	protected :
		std::string type;

	public :

/* ================= Constructor & Destructor ================= */

		WrongAnimal();
		WrongAnimal(const WrongAnimal &other);
		virtual ~WrongAnimal();

/* ========================= Getter ========================= */

		virtual std::string getType( void ) const ;

/* ========================= Else ========================= */

		virtual void makeSound() const;
};