#include "PhoneBook.hpp"

/* ============ Constructor & Destructor ============ */

PhoneBook::PhoneBook()
{
}
PhoneBook::~PhoneBook()
{
}
		
/* ==================== Setters ==================== */

void	PhoneBook::Set_PhoneBook(void)
{
	int i = -1;
	this->next_to_replace = 0;

	while (++i <= 7)
	{
		this->contact[i] = Contact();
		this->contact[i].Set_id(i);
		this->contact[i].Set_FirstName("");
		this->contact[i].Set_LastName("");
		this->contact[i].Set_NickName("");
		this->contact[i].Set_PhoneNumber("");
		this->contact[i].Set_DarkestSecret("");
	}
	return ;
}

void PhoneBook::Set_NewContact(Contact contact)
{
	this->contact[this->next_to_replace] = contact;
}

void PhoneBook::Set_NextToReplace(void)
{
	if (this->next_to_replace == 7)
		this->next_to_replace = 0;
	else if (this->next_to_replace < 7)
		this->next_to_replace = this->next_to_replace + 1;
}


/* ==================== Getters ==================== */

Contact PhoneBook::Get_Contact(int index)
{
	return this->contact[index];
}
Contact PhoneBook::Get_NextToReplace(void)
{
	return this->contact[this->next_to_replace];
}

/* ===================== Else ===================== */