#pragma once

#include "Contact.hpp"

class PhoneBook
{
	private:

		Contact	contact[8];
		int		next_to_replace;

	public:

/* ============ Constructor & Destructor ============ */

		PhoneBook();
		~PhoneBook();
		
/* ==================== Setters ==================== */

		void	Set_PhoneBook(void);
		void	Set_NextToReplace(int i);
		void	Set_NewContact(Contact contact);

/* ==================== Getters ==================== */

		Contact Get_Contact(int index);
		int		Get_NextToReplace(void);

/* ===================== Else ===================== */

};