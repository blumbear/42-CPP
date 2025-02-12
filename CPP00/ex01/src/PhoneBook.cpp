/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:32:53 by ttaquet           #+#    #+#             */
/*   Updated: 2025/02/12 16:32:53 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/* ============ Constructor & Destructor ============ */

PhoneBook::PhoneBook() {}

PhoneBook::~PhoneBook() {}
		
/* ==================== Setters ==================== */

void	PhoneBook::Set_PhoneBook(void)
{
	this->next_to_replace = 0;
	return ;
}

void PhoneBook::Set_NewContact(Contact contact)
{
	this->contact[this->next_to_replace] = contact;
}

void PhoneBook::Set_NextToReplace(int i)
{
	if (i >= 7)
		this->next_to_replace = 0;
	else
		this->next_to_replace = i + 1;
}


/* ==================== Getters ==================== */

Contact PhoneBook::Get_Contact(int index)
{
	return this->contact[index];
}
int PhoneBook::Get_NextToReplace(void)
{
	return this->next_to_replace;
}

/* ===================== Else ===================== */