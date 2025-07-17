#pragma once

#include <exception>
#include <list>
#include <iostream>
#include <string>

class numberCantBeAdded : public std::exception {
public:
	const char* what() const throw() {
		return ("No number can be added.");}
};

class NotEnoughNumber : public std::exception {
public:
	const char* what() const throw() {
		return ("No enough number is in the Span.");}
};

class Span {
	private :
		std::list<int>	_container;
		unsigned int	_n;

	public :
/* ================= Canonical Form ================= */
		Span();
		Span(unsigned int n);
		Span(const Span &other);
		~Span();
		Span &operator=(const Span &other);

/* ================ Member Function ================ */

	void addNumber(int n);
	void addNumber(int start, int end);
	int shortestSpan();
	int longestSpan();
};