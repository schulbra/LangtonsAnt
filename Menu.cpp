/*************************************************************
** Name: Brandon Schultz
** Date 4-9-19
** Project One: Menu.hpp
** Description: This file contains information for implementation 
** of the menu class for Project 1's Langton's Ant Rule Simulation.
/************************************************************/

#include "Menu.hpp"

Menu::Menu()
{
 title = "Menu";
 numChoices = 0;
}
Menu::Menu(string inTitle)
{
 title = inTitle;
 numChoices = 0;
}

void Menu::addMenuChoice(string inMenuChoice)
{
 menuChoices.push_back(inMenuChoice);
 numChoices++;
}

int Menu::getUserChoice()
 {
	cout << "Choose a menu option: ";
	int choice = integerValidation();
	while (choice < 1 || choice > numChoices)
		{
		 cout << "Enter a menu choice 1-" << numChoices << "." << endl;
		 choice = integerValidation();
		}
	return choice;
}

void Menu::displayMenu()
 {
	cout << title << endl;
	for (int i = 0; i < numChoices; i++)
	 {
	  cout << setw(3) << i + 1 << ". " << menuChoices[i] << endl;
	 }
	cout << endl;
}