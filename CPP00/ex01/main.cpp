#include <iostream>
#include <string>
#include <cstring>
#include "PhoneBook.hpp"

void	add_prompt(int i)
{
	if (i == 1)
		std::cout << "Enter First Name :" << std::endl;
	else if (i == 2)
		std::cout << "Enter Last Name :" << std::endl;
	else if (i == 3)
		std::cout << "Enter Nick Name :" << std::endl;
	else if (i == 4)
		std::cout << "Enter The Phone Number :" << std::endl;
	else if (i == 5)
		std::cout << "Enter The Darkest Secret :" << std::endl;
}

int ft_strlen(std::string str)
{
	int i = -1;
	while (str[++i])
		continue;
	return (i);
}

std::string id_to_string(int id)
{
	std::string res = "0";

	res[0] = id + '0' ;
	return (res);
}

void print_column(std::string to_print, bool print_pipe)
{
	int tmp = 0;
	if (ft_strlen(to_print) <= 10)
	{
		tmp = 10 - ft_strlen(to_print);
		while (tmp-- > 0)
			std::cout << " ";
		std::cout << to_print;
	}
	else
	{
		to_print[9] = '.';
		to_print[10] = '\0';
		std::cout << to_print;
	}
	if (print_pipe)
		std::cout << "|";
	else
		std::cout << "\n";
}

void print_contact(Contact contact)
{
	std::cout << "     Index|First Name| Last Name|  NickName" << std::endl;
	std::cout << "----------|----------|----------|----------" << std::endl;
	
	print_column(id_to_string(contact.Get_id()), true);
	print_column(contact.Get_FirstName(), true);
	print_column(contact.Get_LastName(), true);
	print_column(contact.Get_NickName(), false);
}

void search_function(PhoneBook *phonebook)
{
	std::string entry;
	int i = -1;

	std::cout << "SEARCH MODE" << std::endl;
	std::cout << "FIND : ";
	if (!getline(std::cin, entry))
	{
		return ;
	}
	while(++i < 7)
	{
		std::cout << phonebook->Get_Contact(i).Get_NickName() << std::endl;
		if (phonebook->Get_Contact(i).Get_NickName() == entry)
		{
			print_contact(phonebook->Get_Contact(i));
			return ;
		}
	}
	std::cout << "kk" << std::endl;
	return ;
}

void add_function(PhoneBook *phonebook)
{
	std::string entry;
	int i = 0;
	Contact contact = phonebook->Get_NextToReplace();

	std::cout << "ADD MODE" << std::endl;
	while (++i <= 5)
	{
		add_prompt(i);
		if (!getline(std::cin, entry))
		{
			return ;
		}
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
	std::cout << "The Contact Has Been Successfully Added";
	phonebook->Set_NextToReplace();
}

void find_command(std::string command, PhoneBook *phonebook)
{
	if (command == "ADD")
		add_function(phonebook);
	else if (command == "SEARCH")
		search_function(phonebook);
	// else if (command == "EXIT")
	// 	exit_function();
}

int main(void)
{
	std::string command;
	PhoneBook phonebook = PhoneBook();

	phonebook.Set_PhoneBook();
	while(true)
	{
		if (!getline(std::cin, command))
		{
			return (false);
		}
		find_command(command, &phonebook);
	}
	return(true);
}