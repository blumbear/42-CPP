#pragma once

template <typename T> class Array {
	private :
		T *array;
	
	public :
/* ================= Canonical Form ================= */
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		~Array();
		Array &operator=(const Array &other);

/* ================= Other Function ================= */

		unsigned int size() const;
};

#include "Array.tpp"