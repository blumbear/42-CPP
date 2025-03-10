#pragma once

#include "Animal.h" 
#include <string>
#include <iostream>

class Animal {
	protected :
		std::string type;

	public :

/* ================= Constructor & Destructor ================= */

		Animal();
		Animal(const Animal &other);
		virtual ~Animal();

/* ========================= Getter ========================= */

		virtual std::string getType( void ) const ;

/* ========================= Else ========================= */

		virtual void makeSound() const;
};