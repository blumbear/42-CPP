#pragma once

#include <iostream>

template <typename T> void printElement(T const &element) {
	std::cout << element << std::endl;
}

template <typename T, typename V> void iter(T *array, size_t length, V f) {
	for (size_t i = 0; i < length ; i++)
		f(array[i]);
}