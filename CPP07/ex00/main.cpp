#include "whatever.hpp"
#include <iostream>
#include <string>

int main() {
	std::cout << "---- Subject ----" << std::endl;
	int a = 2;
	int b = 3;
	swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	std::cout << "---- Other ----" << std::endl;
	std::cout << min(8,5) << std::endl;
	std::cout << min(5,8) << std::endl;
	std::cout << min(-25,25) << std::endl;
	std::cout << min(8.5,5.5) << std::endl;
	std::cout << min(8.8f,8.9f) << std::endl << std::endl;

	std::cout << max(8,5) << std::endl;
	std::cout << max(5,8) << std::endl;
	std::cout << max(-25,25) << std::endl;
	std::cout << max(8.5,5.5) << std::endl;
	std::cout << max(8.8f,8.9f) << std::endl << std::endl;

	std::string tmpa = "hello";
	std::string tmpb = "world";
	
	swap(tmpa, tmpb);

	std::cout << tmpa << " " << tmpb << std::endl;

	swap(tmpa, tmpb);
	std::cout << tmpa << " " << tmpb << std::endl;
	return (1);
}
