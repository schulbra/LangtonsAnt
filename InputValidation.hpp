/*************************************************************
** Name: Brandon Schultz
** Date 4-9-19
** Project One: InputValidation.hpp
** Description: Header file for InputValidation.cpp.
************************************************************/

#ifndef INPUTVALIDATION_HPP
#define INPUTVALIDATION_HPP

#include <iostream>
#include <cctype>
#include <string>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::string;

//Validates that user entered an integer value.
int integerValidation();
//Validates string for special charcaters. True if contained, otherwise false.
bool containsSymbol(string inStr);
//Check string for spaces. True if contains space, otherwise false.
bool containsSpace(string inStr);
//Validates user defined integer and establishes a max intger that user cant surpass.
int posIntVal(int max = 0);

#endif //INPUTVALIDATION_HPP