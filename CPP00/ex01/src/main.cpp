/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:32:46 by ttaquet           #+#    #+#             */
/*   Updated: 2025/02/17 13:18:14 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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

void	display_ascii_header(const char *command)
{
	std::cout << "\033[32m";
	system(command);
	std::cout << "\033[0m";
}


void search_function(PhoneBook phonebook)
{
	std::string entry;

	system("clear");
	color_print("green", " ____  ___    _    _____   ____  _   _    _ __ ___   _____  ____   ___ ", true);
	color_print("green", "|  __)/ _ \\  / \\  |  ___) /  __)| |_| |  | '_ ` _ \\ /  _  \\|  _ \\ / _ \\", true);
	color_print("green", "|__  |  __/ / △ \\ | |\\ \\ (  (__ |  _  |  | | | | | |  |_|  | |_| |  __/", true);
	color_print("green", "(____|\\___|/_/ \\_\\|_| \\_\\ \\____)|_| |_|  |_| |_| |_|\\_____/|____/ \\___|", true);
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
	system("clear");
	color_print("green", "		    ___        _____ _____ ", true);
	color_print("green", "		   / _ \\__  __|_   _|_   _|", true);
	color_print("green", "		  |  __/\\ \\/ / _| |_  | |  ", true);
	color_print("green", "		   \\___|/_/\\_\\|_____| |_|  ", true);
	return (true);
}

void add_function(PhoneBook *phonebook)
{
	Contact contact = Contact();
	std::string entry;
	int j = -1;
	int i = 0;
	int tmp = true;
	
	system("clear");
	std::cout << "\033[32m    ADD MODE\033[0m" << '\n';
	while (++i <= 5)
	{
		add_prompt(i);
		if (!getline(std::cin, entry))
			return ;
		if (i == 1)
		{
			tmp = false;
			while (tmp == false)
			{
				j = -1;
				while (entry[++j])
				{
					if (entry[j] >= '0' && entry[j] <= '9')
					{
						color_print("red", "Error -> ", false);
						std::cout << "The string can't contain any digit" << '\n';
						break;
					}
					tmp = true;
				}
				if (tmp == false)
				{
					add_prompt(i);
					if (!getline(std::cin, entry))
						return ;
				}
				contact.Set_FirstName(entry);
			}
		}
		if (i == 2)
		{
			tmp = false;
			while (tmp == false)
			{
				j = -1;
				while (entry[++j])
				{
					if (entry[j] >= '0' && entry[j] <= '9')
					{
						color_print("red", "Error -> ", false);
						std::cout << "The string can't contain any digit" << '\n';
						break;
					}
					tmp = true;
				}
				if (tmp == false)
				{
					add_prompt(i);
					if (!getline(std::cin, entry))
						return ;
				}
				contact.Set_LastName(entry);
			}
		}
		if (i == 3)
			contact.Set_NickName(entry);
		if (i == 4)
		{
			tmp = false;
			while (tmp == false)
			{
				j = -1;
				while (entry[++j])
				{
					if (entry.size() != 10)
					{
						color_print("red", "Error -> ", false);
						std::cout << "The string can contain only 10 digit" << '\n';
						break;
					}
					if (entry[j] < '0' || entry[j] > '9')
					{
						color_print("red", "Error -> ", false);
						std::cout << "The string can contain only 10 digit" << '\n';
						break;
					}
				}
				if (j == 10 && entry.size() == 10)
					tmp = true;
				if (tmp == false)
				{
					add_prompt(i);
					if (!getline(std::cin, entry))
						return ;
				}
			}
			contact.Set_PhoneNumber(entry);
		}
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
	phonebook.~PhoneBook();
	return(true);
}