#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

class Brain {
	private:
		std::string ideas[100];

	public:
/* ================= Canonical Form ================= */

		Brain();
		Brain(const Brain &other);
		virtual ~Brain();
		Brain &operator=(const Brain &other);

/* ================= Member function ================= */

		void add_ideas(std::string new_idea);
		void display_ideas(void);
};