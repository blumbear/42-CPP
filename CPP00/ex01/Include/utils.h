#pragma once

#include "PhoneBook.hpp"

/* ================ Print Function ================ */

void	color_print(std::string color, std::string to_write, bool endl);
void	print_column(std::string to_print, bool print_pipe, bool endl);
void	print_contact_list(PhoneBook phonebook);
void	print_contact(Contact contact);	
void	Display_home(void);

/* ================ Print Function ================ */
