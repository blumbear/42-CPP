#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <cstdlib>
#include <sstream>
#include <iomanip>  // pour std::fixed et std::setprecision

#define BISEXTILE(Value) ((Value % 4 == 0 && Value % 100 != 0) || (Value % 4 == 0 && Value % 400 == 0))

#define INPUT_DELIMITER "|"
#define DATA_DELIMITER ","
#define DATE_DELIMITER "-"
#define DATA_BASE "data.csv"

#define ERROR_PROMPT "Error: "

#define USAGE_ERROR "Usage: ./btc <filename>."
#define FILE_ERROR "Could not open file."
#define INPUT_ERROR "bad input => "
#define VALUETOOLOW_ERROR "not a positive number."
#define VALUETOOHIGHT_ERROR "number greater than 1000."
#define DBPARSE_ERROR "Failed to parse the database."

bool parse(char *_file);