#include "RPN.hpp"

/* ================ Exception Handler ================ */

const char* RPN::NotEnoughValueInStack::what() const throw() {
	return (STACK_ERROR);
}

/* ================= Canonical Form ================= */

RPN::RPN() : _stackSize(0) {}

RPN::RPN(const RPN &other) {
	*this = other;
}

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &other) {
	if (this != &other) {
		_stack = other._stack;
		_stackSize = other._stackSize;
	}
	return (*this);
}

/* ================= Member Function ================= */

void RPN::addNumber(const int n){
	_stack.push(n);
	_stackSize++;
}

void RPN::plus(){
	int tmp = _stack.top();

	if (_stackSize < 2)
		throw (NotEnoughValueInStack());
	_stackSize--;
	_stack.pop();
	_stack.top() += tmp;
}

void RPN::minus(){
	int tmp = _stack.top();

	if (_stackSize < 2)
		throw (NotEnoughValueInStack());
	_stackSize--;
	_stack.pop();
	_stack.top() -= tmp;
}

void RPN::multiply(){
	int tmp = _stack.top();

	if (_stackSize < 2)
		throw (NotEnoughValueInStack());
	_stackSize--;
	_stack.pop();
	_stack.top() *= tmp;
}

void RPN::divide(){
	int tmp = _stack.top();

	if (_stackSize < 2)
		throw (NotEnoughValueInStack());
	_stackSize--;
	_stack.pop();
	_stack.top() /= tmp;
}

void RPN::printRes() {
	int tmp = _stack.top();
	
	_stack.pop();
	std::cout << tmp << std::endl;
}