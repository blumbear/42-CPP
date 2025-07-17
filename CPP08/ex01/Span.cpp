#include "Span.hpp"

/* ================= Canonical Form ================= */

Span::Span() : _n(10000) {}

Span::Span(unsigned int n) : _n(n) {}

Span::Span(const Span &other) {
	*this = other;
}

Span::~Span() {}

Span &Span::operator=(const Span &other) {
	if (this != &other)
	{
		_container = other._container;
	}
	return (*this);
}

/* ================ Member Function ================ */

void Span::addNumber(int newNumber) {
	if (_container.size() < _n)
		_container.push_back(newNumber);
	else
		throw numberCantBeAdded();
}

void Span::addNumber(int start, int end) {
	while (start <= end)
	{
		if (_container.size() < _n)
			_container.push_back(start);
		else {
			throw numberCantBeAdded();
			break;
		}
		start++;
	}
}

int Span::shortestSpan() {
	int tmp = _container.front();
	for (std::list<int>::iterator it = _container.begin(); it != _container.end(); ++it) {
		if (*it < tmp) tmp = *it;
	}
	return (tmp);
}

int Span::longestSpan() {
	int tmp = _container.front();
	for (std::list<int>::iterator it = _container.begin(); it != _container.end(); ++it) {
		if (*it > tmp) tmp = *it;
	}
	return (tmp);
}
