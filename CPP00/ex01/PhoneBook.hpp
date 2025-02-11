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
		void	Set_NextToReplace(void);
		void	Set_NewContact(Contact contact);

/* ==================== Getters ==================== */

		Contact Get_Contact(int index);
		Contact Get_NextToReplace(void);

/* ===================== Else ===================== */

};