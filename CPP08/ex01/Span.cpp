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
	if (_container.size() < 2)
		throw NotEnoughNumber();
	std::vector<int> tmp(_container);
	std::sort(tmp.begin(), tmp.end());
	int res = tmp[1] - tmp[0];
	for (size_t i = 0; i < tmp.size() - 1; i++) {
		if (tmp[i + 1] - tmp[i] <= res)
			res = tmp[i + 1] - tmp[i];
	}
	return (res);
}

int Span::longestSpan() {
	if (_container.size() < 2)
		throw NotEnoughNumber();
	std::vector<int> tmp(_container);
	std::sort(tmp.begin(), tmp.end());
	int min = *std::min_element(tmp.begin(), tmp.end());
	int max = *std::max_element(tmp.begin(), tmp.end());
	return (max - min);
}
