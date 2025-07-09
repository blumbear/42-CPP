#pragma once

#include "Serializer.hpp"

class Data : public Serializer {
	private: 
		void *_data;

	public:
	/* ================= Canonical Form ================= */

		Data();
		Data(const Data &other);
		~Data();
		Data &operator=(const Data &other);

	/* ================= Getter/Setter ================= */
		void* getData() const;
};