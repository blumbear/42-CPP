#pragma once

template <typename T> void swap (T a, T b) {
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}

template <typename T> T min (T a, T b) {
	T result;
	result = (a < b)? a : b;
	result = (a == b)? b : result;
	return (result);
}

template <typename T> T max (T a, T b) {
	T result;
	result = (a > b)? a : b;
	result = (a == b)? b : result;
	return (result);
}