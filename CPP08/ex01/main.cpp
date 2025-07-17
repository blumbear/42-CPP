#include "Span.hpp"

#include <vector>
#include <ctime>
#include <algorithm>

int main(int ac, char **av) {
	if (ac == 1){
		std::cerr << "Usage: .Span <option>\nOption: 'a' or 'b'" << std::endl;
		return (0);
	}
	if (av[1][0] == 'a') {
		Span container=Span();
		for (int i = 0; i < 11111; i++) {
			try {
				container.addNumber(std::time(0));}
			catch (std::exception &e){
				std::cerr << e.what() << std::endl;
				break;
			}
		}
		try {
			std::cout << container.longestSpan() << std::endl;}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		
		try {
			std::cout << container.shortestSpan() << std::endl;}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	else if (av[1][0] == 'b') {
		Span container=Span();
		container.addNumber(-10, 9950);
		try {
			std::cout << container.longestSpan() << std::endl;}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}

		try {
			std::cout << container.shortestSpan() << std::endl;}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	
	
}