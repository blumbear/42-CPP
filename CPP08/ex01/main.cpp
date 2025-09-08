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
		for (int i = 0; i < 1111; i++) {
			try {
				container.addNumber(i);}
			catch (std::exception &e){
				std::cerr << e.what() << std::endl;
				return 0;
			}
		}
		try {
			container.addNumber(50000);
		} catch (std::exception &e){
			std::cerr << e.what() << std::endl;
			return 0;
		}
		try {
			std::cout << container.longestSpan() << std::endl;}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
			return 0;
		}
		
		try {
			std::cout << container.shortestSpan() << std::endl;}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
			return 0;
		}
	}
	else if (av[1][0] == 'b') {
		Span container=Span();
		container.addNumber(-10, 9950);
		try {
			std::cout << container.longestSpan() << std::endl;}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
			return 0;
		}

		try {
			std::cout << container.shortestSpan() << std::endl;}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
			return 0;
		}
	}
	
	
}