#pragma once

#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>

class Contact
{
	private:

		int id;
		std::string FirstName;
		std::string LastName;
		std::string NickName;
		std::string PhoneNumber;
		std::string DarkestSecret;

	public:

/* ============ Constructor & Destructor ============ */

		Contact();
		~Contact();

/* ==================== Setters ==================== */

		void	Set_id(int id);
		void	Set_FirstName(std::string FirstName);
		void	Set_LastName(std::string LastName);
		void	Set_NickName(std::string NickName);
		void	Set_PhoneNumber(std::string PhoneNumber);
		void	Set_DarkestSecret(std::string DarkestSecret);

/* ==================== Getters ==================== */
	
		int	Get_id(void);
		std::string	Get_FirstName(void);
		std::string	Get_LastName(void);
		std::string	Get_NickName(void);
		std::string	Get_PhoneNumber(void);
		std::string	Get_DarkestSecret(void);
};
