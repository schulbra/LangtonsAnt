/*************************************************************
** Name: Brandon Schultz
** Date 4-9-19
** Project One: Ant.hpp
** Description: Header file containing function descriptions
** for"Ant.cpp".
*************************************************************/

#ifndef ANT_HPP
#define ANT_HPP
#include <iostream>

using std::cout;
using std::endl;
using std::cin;
//Direction faced by ant.
enum AntPosition { Up, Left, Down, Right };

class Ant
{
private:
	int boardRows; //Sets number of rows, or horizontal movement options. 
	int boardColumns; //Sets number of columns, or vertical movement options.
	int antRow; //Sets row integer value on board occupied by ant.
	int antColumn; //Sets column integer value on board occupied by ant
	int** board; //Object made representing total rows, columns.
	AntPosition antDir;
	//Used to validate space occupied by ant without the board getting destroyed. 
	void updateSpaceState();
	//Function used to accomadate edges of board. Bool compares if ant is touching
	//boardering an edge.
	bool isFacingWall();
	//Function containing movement directions regarding how the ant will move in response to 
	//obtained bool from line 31. Basically, the ant moves away from spaces that boarder walls.
	void rotateAnt();

public:
	Ant(); //Deafault constructor.
	//Constructor for ant class input.
	Ant(int inBoardRows, int inBoardColumns, int inAntRow, int inAntColumn, AntPosition inAntDir);
	//Destructor for whiping data members that were passed as arguements via lines 37-39.
	~Ant();
	//Function for ants movement. Used in "void updateSpaceState();", "bool isFacingWall();", ...
	void moveAnt();
	//Displays ant status.
	void printBoard();
};

#endif //ANT_HPP