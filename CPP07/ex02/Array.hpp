#pragma once

#include <exception>
#include <string>
#include <iostream>

template <typename T> class Array {
	private :
		T *_array;
		unsigned int _size;
	
	public :
/* ================= Canonical Form ================= */
		Array(): _array(NULL), _size(0) {}
		Array(unsigned int n) : _array(new T[n]), _size(n) {}
		Array(const Array &other) : _array(new T[other._size]), _size(other._size) {
			for (unsigned int i = 0; i < _size; i++) {_array[i] = other._array[i];}
		}
		~Array() {}
		Array &operator=(const Array &other) {
			if(this != &other){
				delete _array;
				_size = other._size;
				_array = new T[_size];
				for (unsigned int i = 0; i < _size; i++){_array[i] = other._array[i];}
			} return *this;
		}

/* ================= Other Function ================= */

		unsigned int size() const {return _size;}

/* =============== Overload Operator =============== */
		T	&operator[](unsigned int i) {return (i >= this->_size? throw Array::OutOfBounds() : (_array[i]));}
		T const &operator[](unsigned int i)const {return (i >= this->_size? throw Array::OutOfBounds() : (_array[i]));}

		class OutOfBounds : public std::exception
		{
			public:
				virtual const char *what() const throw() {return "Error : Out of Bound";}
		};
};