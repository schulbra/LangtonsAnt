/*************************************************************
** Name: Brandon Schultz
** Date 4-9-19
** Project One: Menu.hpp
** Description: Header file for menu class of Project 1's 
** Langton's Ant Rule Simulation.
************************************************************/
#ifndef MENU_HPP
#define MENU_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include "InputValidation.hpp"

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::setw;

class Menu
{
private:
	string title;
	vector<string> menuChoices;
	int numChoices;
public:
	//Default constructor for Menu class.
	Menu();
	//Parameter accepting constructor for Menu class. 
	Menu(string inTitle);
	//Adds menu option to menuChoices vector based on users input.
	void addMenuChoice(string inMenuChoice);
	//Validates users menu choice.
	int getUserChoice();
	//Prints menu to user.
	void displayMenu();
};

#endif //MENU_HPP