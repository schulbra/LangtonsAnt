/*************************************************************
** Name: Brandon Schultz
** Date 4-9-19
** Project One: MAIN file for Langton's Ant Rule Simulation
** Description: Source file for testing Project 1's Langton's Ant Rule Simulation.
** Contains an attempt at extra credit assignment requiring rnadom placement of ant.
** Files used can be found below:
**	# InputValidation.cpp
**	# InputValidation.hpp
**	# Ant.cpp
**	# Ant.hpp
**	# Menu.cpp
**	# Menu.hpp
************************************************************/

#include "Ant.hpp"
#include "Menu.hpp"
#include "InputValidation.hpp"
//Used for placing ant at random location.
#include <ctime>
//Used to generate value representative of ants placement if random
//is selected.
#include <cstdlib> 

void simulation();
int getRandStart(int max);
int main()
{
	Menu startMenu("Project One: Langton's Ant Simulation.");
	 startMenu.addMenuChoice("Start Langton's Ant Simulation.");
	 startMenu.addMenuChoice("Quit Langton's Ant Simulation.");
	 startMenu.displayMenu();
 int choice = startMenu.getUserChoice();
	if (choice == 1)
	{
		simulation();
		Menu continueMenu("Continue Langton's Ant Simulation.");
		continueMenu.addMenuChoice("Play again.");
		continueMenu.addMenuChoice("Quit Langton's Ant Simulation.");
	while (choice == 1)
	{
		 continueMenu.displayMenu();
		 choice = continueMenu.getUserChoice();
	if (choice == 1)
	{
		 simulation();
	}
    }
 }
return 0;
}

//Function for running Langton's Ant Simulation once.
void simulation()
{
 //Obtain user defined # of rows.
 cout << "Please choose the number of rows for simulation: ";
 int boardRows = posIntVal();
 //Obtain user defined # of columns.
 cout << "Please choose the number of columns for simulation: ";
 int boardColumns = posIntVal();
 Menu randomStart("CHOOSE HOW YOUR ANT OBJECT WILL BE INITIALLY PLACED:");
  randomStart.addMenuChoice("I WANT TO CHOOSE");
  randomStart.addMenuChoice("RANDOM");
  randomStart.displayMenu();
 int random = randomStart.getUserChoice();//Scans users input.
 int startAntRow; //Ant row initial placement value.
 int startAntColumn; //Ant column initial placement value.
 //If random is chosen the starting point is established.
  if (random == 1)
   {
	//Time arguement is passed to srand, generating random values
	//for inital row and column placement of Langton's Ant if
	// "RANDOM" is selected.
	unsigned seed;
	seed = time(0); 
	srand(seed);

	//User is prompted for # of rows, columns if random isnt slected.
	cout << "Ant initial row value: ";
	startAntRow = posIntVal(boardRows);
	cout << "Ant initial column value: ";
	startAntColumn = posIntVal(boardColumns);
   }
  else
  {
	 startAntRow = getRandStart(boardRows);
	 startAntColumn = getRandStart(boardColumns);
  }
    //Menu for setting ant's initial movement pattern.
    Menu antDirection("Initial direction faced by ant:");
    antDirection.addMenuChoice("Up");
    antDirection.addMenuChoice("Right");
    antDirection.addMenuChoice("Down");
    antDirection.addMenuChoice("Left");
    antDirection.displayMenu();
//Sets number of steps that simulations an will take. One step=One change of space.
 int antStartDirection = antDirection.getUserChoice() - 1;
 cout << "Enter steps taken by Langton's Ant for simulation ";
 int steps = posIntVal();
 Ant theAnt(boardRows, boardColumns, startAntRow, startAntColumn, static_cast<AntPosition>(antStartDirection));
  for (int i = 0; i < steps; i++)
	{
	 theAnt.printBoard();
	 theAnt.moveAnt();
	}
 cout << "Langton's Ant took " << steps << " steps." << endl << endl;
}
//Function for random starting location called.
int getRandStart(int max)
{

	return rand() % max + 1;
}