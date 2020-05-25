/*************************************************************
** Name: Brandon Schultz
** Date 4-9-19
** Project One: Ant.cpp
** Description: This file contains information for implementation 
** of the ant class.
************************************************************/
#include "Ant.hpp"

//Default constructor for ant class.
Ant::Ant()
{
 //20x20 array for movement options.
 boardRows = 20;
 boardColumns = 20;
 //Note that board values initalize at 0, so antRow, antColumn actual placement postiions
 //for default constructor would be 10th row, 10th column.
 antRow = 9;
 antColumn = 9;
 antDir = Down;
 board = new int*[boardRows];
  for (int i = 0; i < boardRows; i++)
	{
	 board[i] = new int[boardColumns];
	}
  //Initializes boardRows, boardColumns to 0.
  for (int i = 0; i < boardRows; i++)
	{
     for (int j = 0; j < boardColumns; j++)
		{
		 board[i][j] = 0;
     }
  }
 }
	
//Parameter taking constructor for ant class.
Ant::Ant(int inBoardRows, int inBoardColumns, int inAntRow, int inAntColumn, AntPosition inAntDir)
{
 boardRows = inBoardRows;//Row spaces, or horizontal movement options.
 boardColumns = inBoardColumns;//Column spaces, or vertical movement options
 antRow = inAntRow - 1;//Row location of ant.
 antColumn = inAntColumn - 1;//Column location of ant.
 antDir = inAntDir;
 bool isFacingWall();
 board = new int*[boardRows];
 for (int i = 0; i < boardRows; i++)
	{
	 board[i] = new int[boardColumns];
	}
 //Initializes boardRows, boardColumns to 0.
 for (int i = 0; i < boardRows; i++)
    {
     for (int j = 0; j < boardColumns; j++)
	{
	 board[i][j] = 0;
	}
   }
}

//Destructor for whiping memory.
Ant::~Ant()
{
 for (int i = 0; i < boardRows; i++)
	{
	 delete [] board[i];
	}
 delete [] board;
 board = nullptr;
}

void Ant::printBoard()
{
 //Function for displaying boards top edge. 
 for (int i = 0; i < (boardColumns + 2); i++)
 {
	cout << "-";
 }
 cout << endl;
 //Function for displaying board rright, left edges.
 for (int i = 0; i < boardRows; i++)
 {
   cout << "|";
   for (int j = 0; j < boardColumns; j++)
   {
	//Whitespace character value for space occupied by ant.
	char space = 32; 
	if (i == antRow && j == antColumn)
		{
		 //Symbol denoting ant on board.
		 space = '*';
		}
	else if (board[i][j] == 1)
		{    
		 //Black space charcter on board
		  space = '#';
		}
	 //White space chacracter on board.
     cout << space;
   }
 cout << "|" << endl;
 }
 //Function for displaying boards lowest edge.
 for (int i = 0; i < (boardColumns + 2); i++)
 {
  cout << "-";
 }
  cout << endl;
 }

//Function used for updating the board after ant moves from one space to another.
void Ant::updateSpaceState()
{
 if (board[antRow][antColumn] == 0)
 {
   board[antRow][antColumn] = 1;
 }
 else
  {
   board[antRow][antColumn] = 0;
  }
}

//Function for moving ant in relation to spaces that boarder ants, occupied space. If true, ant faces
//some edge. Obtained bools is used in "void rotateAnt" function to prevent ant from moving off board.
bool Ant::isFacingWall() 
{
 //If row space occupied  by ant = board horizontal length - 1 space, ant is facing some edge.
 int maxAntRow = boardRows - 1;
 //If column space occupied  by ant = board vertical length - 1 space, ant is facing some edge.
 int maxAntCol = boardColumns - 1;
  //Checks to see if ant boarders top most edge.
  if (antRow == 0 && antDir == Up)
	{
	 return true;
	}
		//Checks to see if ant boarders lower most edge
		else if (antRow == maxAntRow && antDir == Down)
			{
				return true;
			}
		//Checks to see if ant boarders left most edge.
		else if (antColumn == 0 && antDir == Right)
			{
				return true;
			}
		//Checks to see if ant boarders right most edge.
		else if (antColumn == maxAntCol && antDir == Left)
			{
				return true;
			}
  //Ant does not face an edge.
  else
	{
	 return false;
	}
 }

// If the ant is on a black space, turn left 90 degreesand change the space to white.
void Ant::rotateAnt()
{
 int antDirInt = antDir;
 //Function for if the ant is found to be on a white space, turning it right 90 
 //degrees and changing the space to black.
 if (board[antRow][antColumn] == 0)
	{
	 antDirInt = (antDirInt + 1) % 4;
	 antDir = static_cast<AntPosition>(antDirInt);
	}
 //Function for if the ant is found to be on a black space, turning it right 90 
 //degrees and changing the space to white.
 else 	
	{
	 antDirInt = (antDirInt + 3) % 4;
	 antDir = static_cast<AntPosition>(antDirInt);
	}
 //Function for turning ant away from edge based on obtained bool.
 if (isFacingWall())
	{
	 antDirInt = (antDirInt + 2)  % 4;
	 antDir = static_cast<AntPosition>(antDirInt);
	}
}

//Function for moving ant. Each movement is a singular event in relation to the board and 
//is determined by direction ant is facing and variations in type of spaces it's current 
// position boarders.
void Ant::moveAnt()
{
 rotateAnt(); //Turns ant in direction based on potential edges its current space boarders.
 updateSpaceState(); //Space occupied by ant is validated before ant moves, occupies it.
 if (antDir == Up)
 {
   antRow--;
 }
 else if (antDir == Left)
 {
   antColumn++;
 }
 else if (antDir == Down)
 {
   antRow++;
 }
 else
  {
   antColumn--;
 }
}