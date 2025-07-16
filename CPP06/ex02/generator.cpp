#include "Base.hpp"

/* ================= Other Function ================= */
Base * generate(void){
	srand(time(NULL));
	int random = rand() % 3;
	if (random == 0) {
		 std::cout << "Création d'un objet de type A" << std::endl;
		return new A();
	} else if (random == 1) {
		 std::cout << "Création d'un objet de type B" << std::endl;
		return new B();
	} else {
		 std::cout << "Création d'un objet de type C" << std::endl;
		return new C();
	}
}

void identify(Base* p){
	if (dynamic_cast<A*>(p)) std::cout << "Type A" << std::endl;
	else if (dynamic_cast<B*>(p)) std::cout << "Type B" << std::endl;
	else if (dynamic_cast<C*>(p)) std::cout << "Type C" << std::endl;
	else std::cout << "Type inconnu\n";
}

void identify(Base& p){
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "Type A" << std::endl;
		return ;
	} catch (...) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "Type B" << std::endl;
		return ;
	} catch (...) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "Type C" << std::endl;
		return ;
	} catch (...) {}
	std::cout << "Unknown Type" << std::endl;
}
