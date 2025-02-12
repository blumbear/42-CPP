/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:32:46 by ttaquet           #+#    #+#             */
/*   Updated: 2025/02/12 16:35:49 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "PhoneBook.hpp"

void	add_prompt(int i)
{
	if (i == 1)
		std::cout << "Enter First Name :";
	else if (i == 2)
		std::cout << "Enter Last Name :";
	else if (i == 3)
		std::cout << "Enter NickName :";
	else if (i == 4)
		std::cout << "Enter The Phone Number :";
	else if (i == 5)
		std::cout << "Enter The Darkest Secret :";
}

void search_function(PhoneBook phonebook)
{
	std::string entry;

	system("clear");
	system("bat ascii/search.txt");
	print_contact_list(phonebook);
	std::cout << '\n' << "Enter the index of the \033[36mindex of the desired contact\033[0m or type '\033[36mHOME\033[0m'" << '\n';
	while(true)
	{
		std::cout << "COMMAND : ";
		if (!getline(std::cin, entry))
			return ;
		if (entry.empty())
		{
			color_print("red", "Error-> ", false);
		 	std::cout << "Please Enter the \033[36mindex of the desired contact\033[0m or type '\033[36mHOME\033[0m'" << '\n';
		}
		else if (entry == "HOME")
		{
			break;
		}
		else if (entry < "0" || entry > "7")
		{
			color_print("red", "Error-> ", false);
			std::cout << "The Index Must Be Between 0 and 7" << '\n';
		}
		else if (entry.size() > 1)
		{
			color_print("red", "Error-> ", false);
			std::cout << "The Index Contain Only One Integer" << '\n';
		}
		else
		{
			print_contact(phonebook.Get_Contact(entry[0] - '0'));
		}
	}
	return ;
}

bool exit_function(void)
{
	color_print("green", "		    ___        _____ _____ ", true);
	color_print("green", "		   / _ \\__  __|_   _|_   _|", true);
	color_print("green", "		  |  __/\\ \\/ / _| |_  | |  ", true);
	color_print("green", "		   \\___|/_/\\_\\|_____| |_|  ", true);
	return (true);
}

void add_function(PhoneBook *phonebook)
{
	std::string entry;
	int i = 0;
	Contact contact = Contact();

	system("clear");
	std::cout << "\033[32m    ADD MODE\033[0m" << '\n';
	while (++i <= 5)
	{
		add_prompt(i);
		if (!getline(std::cin, entry))
			return ;
		if (i == 1)
			contact.Set_FirstName(entry);
		if (i == 2)
			contact.Set_LastName(entry);
		if (i == 3)
			contact.Set_NickName(entry);
		if (i == 4)
			contact.Set_PhoneNumber(entry);
		if (i == 5)
			contact.Set_DarkestSecret(entry);

	}
	std::cout << "The Contact Has Been Successfully Added" << '\n';
	phonebook->Set_NewContact(contact);
	phonebook->Set_NextToReplace(phonebook->Get_NextToReplace());
	sleep(2);
}

int main(void)
{
	std::string command;
	PhoneBook phonebook = PhoneBook();

	phonebook.Set_PhoneBook();
	while(true)
	{
		system("clear");
		Display_home();
		if (!getline(std::cin, command))
			return (false);
		if (command == "ADD")
			add_function(&phonebook);
		else if (command == "SEARCH")
			search_function(phonebook);
		else if (command == "EXIT")
			return (exit_function());
	}
	return(true);
}