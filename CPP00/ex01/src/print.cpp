/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:32:55 by ttaquet           #+#    #+#             */
/*   Updated: 2025/02/12 16:36:00 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstring>
#include "utils.h"

std::string id_to_string(int id)
{
	std::string res = "0";

	res[0] = id + '0' ;
	return (res);
}

void print_contact_list(PhoneBook phonebook)
{
	int i = -1;

	color_print("blue", "	    |----------|----------|----------|----------|", true);
	std::cout << "	    \033[34m|\033[0m     Index\033[34m|\033[0mFirst Name\033[34m|\033[0m Last Name\033[34m|\033[0m  NickName\033[34m|\033[0m" << '\n';
	color_print("blue", "	    |----------|----------|----------|----------|", true);
	while (++i <= 7)
	{
		std::cout << "	    ";
		print_column(id_to_string(i), true, false);
		print_column(phonebook.Get_Contact(i).Get_FirstName(), false, false);
		print_column(phonebook.Get_Contact(i).Get_LastName(), false, false);
		print_column(phonebook.Get_Contact(i).Get_NickName(), false, true);
	}
	color_print("blue", "	    |----------|----------|----------|----------|", true);
}

void	print_contact(Contact contact)
{
	std::cout << "	  First Name	-> " << contact.Get_FirstName() << '\n';
	std::cout << "	  Last Name	-> " << contact.Get_LastName() << '\n';
	std::cout << "	   NickName	-> " << contact.Get_NickName() << '\n';
	std::cout << "	 Phone Number	-> " << contact.Get_PhoneNumber() << '\n';
	std::cout << "	Darkest Secret	-> " << contact.Get_DarkestSecret() << '\n';
}

void print_column(std::string to_print, bool print_pipe, bool endl)
{
	int tmp = 0;
	std::string temp;
	if (print_pipe)
		std::cout << "\033[34m|\033[0m";
	if (to_print.size() <= 10)
	{
		tmp = 10 - to_print.size();
		while (tmp-- > 0)
			std::cout << " ";
		std::cout << to_print;
	}
	else
		std::cout << to_print.substr(0, 9) << ".";
	std::cout << "\033[34m|\033[0m";
	if (endl)
		std::cout << "\n";
}

void color_print(std::string color, std::string to_write, bool endl)
{
	if (color == "red")
		std::cout << "\033[31m";
	if (color == "green")
		std::cout << "\033[32m";
	if (color == "yellow")
		std::cout << "\033[33m";
	if (color == "blue")
		std::cout << "\033[34m";
	if (color == "cyan")
		std::cout << "\033[36m";
	std::cout << to_write << "\033[0m";
	if (endl == true)
		std::cout << '\n';
}

void Display_home(void)
{
	color_print("green", "		 _   _  _____  _ __ ___   ___ ", true);
	color_print("green", "		| |_| |/  _  \\| '_ ` _ \\ / _ \\", true);
	color_print("green", "		|  _  |  |_|  | | | | | |  __/", true);
	color_print("green", "		|_| |_|\\_____/|_| |_| |_|\\___|", true);
	std::cout << '\n' << "Command :" << '\n' << '\n';
	color_print("cyan", "  -ADD", true);
	color_print("cyan", "  -SEARCH", true);
	color_print("cyan", "  -EXIT", true);
}