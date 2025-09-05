#pragma once

#include <string>
#include <iostream>
#include <stack>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef std::stack<T> _stack;
	 typedef typename std::stack<T>::container_type::iterator iterator;

	MutantStack() : _stack() {}
	MutantStack(const MutantStack &other) : _stack(other) {}
	~MutantStack() {}

	MutantStack &operator=(const MutantStack &other) {
		if (this != &other)
			_stack::operator=(other);
		return *this;
	}

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }

};