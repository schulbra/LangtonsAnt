/*************************************************************
** Name: Brandon Schultz
** Date 4-9-19
** Project One: InputValidation.cpp
** Description: Implementation file for input validation of 
** Langton's Ant Rule Simulation.
************************************************************/

#include "InputValidation.hpp"
//Integer validation funciton. Uses atoi to pass and interpret str content, 
//returning an int value. This is used to check that the user's input is within
//range of board dimensions, is larger than zero or smaller than max.
int integerValidation()
{
  string str;
  int integer;
  getline(cin, str);
  integer = atoi(str.c_str());
  while (!atoi(str.c_str()) || containsSymbol(str) || containsSpace(str)) 
  {
	if (str.compare("0") == 0)
    {
     return 0;
    }
  cout << "Please enter an integer." << endl;
  getline(cin, str);
  integer = atoi(str.c_str());
  }
 return integer;
}

//Used to ensure that value entered is >0, <max value.
int posIntVal(int max)
{
 string str;
 int integer;
 getline(cin, str);
 integer = atoi(str.c_str());
  if (max == 0)
  {
	while (!atoi(str.c_str()) || containsSymbol(str) || containsSpace(str) || integer < 1)
	{
     cout << "Enter positive integer below:" << endl;
	 getline(cin, str);
	 integer = atoi(str.c_str());
	}
  return integer;
  }
  //Check that value dosent surpass max value.
  else
   {
    while (!atoi(str.c_str()) || containsSymbol(str) || containsSpace(str) || integer < 1 || integer > max)
	{
	 cout << "ERROR. Enter a value within boards dimensions:" << max + 1 << "." << endl;
	 getline(cin, str);
	 integer = atoi(str.c_str());
	}
  return integer;
  }
}

//Used to check users input for symbol input.
bool containsSymbol(string inStr)
{
 int strLen = inStr.length();
  //If symbol is detected return true.
  if (inStr.c_str()[0] == '-')
  {
   for (int i = 1; i < strLen; i++)
   {
   if (ispunct(inStr.c_str()[i]))
 return true;
    }
  }
 else
 {
  for (int i = 0; i < strLen; i++)
  {
   if (ispunct(inStr.c_str()[i]))
 return true;
  }
 }
 //If no symbol detected, return false.
 return false;
}

//Used to check users input for spaces.
bool containsSpace(string inStr)
{
	 int strLen = inStr.length();
	 for (int i = 0; i < strLen; i++)
	 {
		//If space is detected return true.
		if (isspace(inStr.c_str()[i]))
		return true;
	 }
 //If no space detected, return false.
 return false;
}