#include "Contact.hpp"

/* ============ Constructor & Destructor ============ */

Contact::Contact()
{
}

Contact::~Contact()
{
}

/* ==================== Setters ==================== */

void	Contact::Set_id(int id)
{
	this->id = id;
}
void	Contact::Set_FirstName(std::string FirstName)
{
	this->FirstName = FirstName;
}
void	Contact::Set_LastName(std::string LastName)
{
	this->LastName = LastName;
}
void	Contact::Set_NickName(std::string NickName)
{
	this->NickName = NickName;
}
void	Contact::Set_PhoneNumber(std::string PhoneNumber)
{
	this->PhoneNumber = PhoneNumber;
}
void	Contact::Set_DarkestSecret(std::string DarkestSecret)
{
	this->DarkestSecret = DarkestSecret;
}

/* ==================== Getters ==================== */

int	Contact::Get_id(void)
{
	return (this->id);
}
std::string	Contact::Get_FirstName(void)
{
	return this->FirstName;
}
std::string	Contact::Get_LastName(void)
{
	return this->LastName;
}
std::string	Contact::Get_NickName(void)
{
	return this->NickName;
}
std::string	Contact::Get_PhoneNumber(void)
{
	return this->PhoneNumber;
}
std::string	Contact::Get_DarkestSecret(void)
{
	return this->DarkestSecret;
}