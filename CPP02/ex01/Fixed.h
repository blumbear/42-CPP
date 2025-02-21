#pragma once

#include "Fixed.hpp"

#define DFLT_CONSTRUCTOR_ANC "Default constructor called"
#define CPY_CONSTRUCTOR_ANC "Copy constructor called"
#define INT_CONSTRUCTOR_ANC "Int constructor called"
#define FLT_CONSTRUCTOR_ANC "Float constructor called"
#define CPY_ASSIGNMENT_OP_ANC "Copy assignment operator called"
#define GETRAWBITS_ANC "getRawBits member function called"
#define GETBIN_ANC "getBinary member function called"
#define DESTRUCTOR_ANC "Destructor called"

int			ft_pow(int n, int pow);
std::string	intToBin(int number);
int			binaryToInt(std::string binary);
