//tictactoe.cc – DO alter this file.  
//Add your functions above runGame().
//NOTE that I have commented out the functions so it will compile.  You
//MUST uncomment these as you complete them for the game to work and for
//testing.

#include <stdio.h>
#include "tictactoe.h"

void clearBoard(gameData_t *);
void getPlayerInfo(gameData_t *);
void printPlayerInfo(gameData_t);
void printTurnHeader(gameData_t, char);
void printBoard(gameData_t);
void getMove(gameData_t *, char);
int checkWin(gameData_t, char);
int checkTie(gameData_t);

gameData_t *gameData;

void runGame() {
  
  gameData_t gameData;
  
  int win = 0;
  int tie = 0;  
  char turn = 'X';
  
  //Set board to all spaces.
  clearBoard(&gameData);
  
  //Get both players name and age
  getPlayerInfo(&gameData);
  
  //Show the player info
  printf("\n");
  printPlayerInfo(gameData);
  printf("\n");
  
  while (!win && !tie) {
    //int count = 0;
    
    printTurnHeader(gameData, turn); 
    printBoard(gameData);
    getMove(&gameData, turn);    
    
    //Check for win
    win = checkWin(gameData, turn);        
    if (win == 1) {
      printf("--------------------------------------------------\n");      
      if (turn == 'X') {        
        printf("---------- %s WINS! --------------------\n", gameData.name1);
      } else {        
        printf("---------- %s WINS! --------------------\n", gameData.name2);
      }
      printf("--------------------------------------------------\n");      
      printBoard(gameData);
      printf("\n");
    } else {
      tie = checkTie(gameData);        
      if (tie == 1) {
        printf("--------------------------------------------------\n");      
        printf("---------- TIE GAME! --------------------\n");
        printf("--------------------------------------------------\n");      
        printBoard(gameData);
      }
    }
    
    //Toggle turn so other player goes next.
    if (turn == 'X') turn = 'O';
    else turn = 'X';
  }
}

void clearBoard(gameData_t *gameData)
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			gameData -> board[i][j] = ' ';
		}
	}
}

void getPlayerInfo(gameData_t *gameData)
{
	printf("Player 1 enter your name: ");
	scanf("%s", gameData -> name1);
	printf("Player 1 enter your age: ");
	scanf("%d", &gameData -> age1);
	printf("\n");
	printf("Player 2 enter your name: ");
	scanf("%s", gameData -> name2);
	printf("Player 2 enter your age: ");
	scanf("%d", &gameData -> age2);
}

void printPlayerInfo(gameData_t gameData)
{
	printf("Player 1 is %s age %d and will be Xs\n", gameData.name1, gameData.age1);
	printf("Player 2 is %s age %d and will be Os\n", gameData.name2, gameData.age2);
}

void printTurnHeader(gameData_t gameData, char turn)
{
	printf("--------------------------------------------------\n");
	if(turn == 'X')
	{
		printf("---------- %s's Turn --------------------\n", gameData.name1);
		printf("---------- You are Xs --------------------\n");
	}
	else 
	{
		printf("---------- %s's Turn --------------------\n", gameData.name2);
		printf("---------- You are Os --------------------\n");
	}
	printf("--------------------------------------------------\n");
}

void printBoard(gameData_t gameData)
{
	printf("    C1  C2  C3\n");
	printf("R1  %c | %c | %c \n", gameData.board[0][0], gameData.board[0][1], gameData.board[0][2]);
	printf("   -----------\n");
	printf("R2  %c | %c | %c \n", gameData.board[1][0], gameData.board[1][1], gameData.board[1][2]);
	printf("   -----------\n");
	printf("R3  %c | %c | %c \n", gameData.board[2][0], gameData.board[2][1], gameData.board[2][2]);
}

void getMove(gameData_t *gameData, char turn)
{
	char move[5];
	int flag = 0;
	
	if(turn == 'X') //if player 1
	{
		printf("%s, please enter your move in the form RXCY: ", gameData -> name1);
		while(flag == 0)
		{
			scanf("%4s", move);
			
			int x = move[1];
			int y = move[3];
			
			if((move[0] != 'R' && move[0] != 'r' ) || (move[2] != 'C' && move[2] != 'c')) //if not R or r and if not C or c
			{
				printf("Input must be in the form RxCy. Try again: ");
			}
			else if(move[1] < '1' || move[1] > '3' || move[3] < '1' || move[3] > '3') //if numbers are not between 1 and 3
			{
				printf("Row and Column must be in the range 1 to 3. Try again: ");
			}
			else
			{
				if(gameData -> board[x - 49][y - 49] != ' ') //already taken space
				{
					printf("That space is taken. Try again: ");
				}
				else
				{
					gameData -> board[x - 49][y - 49] = 'X';
					flag = 1;
				}
			}
		}
	}
	else // if player 2
	{
		printf("%s, please enter your move in the form RXCY: ", gameData -> name2);
		while(flag == 0)
		{
			scanf("%4s", move);
			
			int x = move[1];
			int y = move[3];
			
			if((move[0] != 'R' && move[0] != 'r' ) || (move[2] != 'C' && move[2] != 'c')) //if not R or r and if not C or c
			{
				printf("Input must be in the form RxCy. Try again: ");
			}
			else if(move[1] < '1' || move[1] > '3' || move[3] < '1' || move[3] > '3') //if numbers are not between 1 and 3
			{
				printf("Row and Column must be in the range 1 to 3. Try again: ");
			}
			else
			{
				if(gameData -> board[x - 49][y - 49] != ' ') //already taken space
				{
					printf("That space is taken. Try again: ");
				}
				else
				{
					gameData -> board[x - 49][y - 49] = 'X';
					flag = 1;
				}
			}
		}
	}
}

int checkWin(gameData_t gameData, char turn)
{
	int win = 0;
	
	if(gameData.board[0][0] == turn && gameData.board[0][1] == turn && gameData.board[0][2] == turn)
	{
		win = 1;
	}
	else if(gameData.board[1][0] == turn && gameData.board[1][1] == turn && gameData.board[1][2] == turn)
	{
		win = 1;
	}
	else if(gameData.board[2][0] == turn && gameData.board[2][1] == turn && gameData.board[2][2] == turn)
	{
		win = 1;
	}
	else if(gameData.board[0][0] == turn && gameData.board[1][0] == turn && gameData.board[2][0] == turn)
	{
		win = 1;
	}
	else if(gameData.board[0][1] == turn && gameData.board[1][1] == turn && gameData.board[2][1] == turn)
	{
		win = 1;
	}
	else if(gameData.board[0][2] == turn && gameData.board[1][2] == turn && gameData.board[2][2] == turn)
	{
		win = 1;
	}
	else if(gameData.board[0][0] == turn && gameData.board[1][1] == turn && gameData.board[2][2] == turn)
	{
		win = 1;
	}
	else if(gameData.board[0][2] == turn && gameData.board[1][1] == turn && gameData.board[2][0] == turn)
	{
		win = 1;
	}
	
	return win;
}

int checkTie(gameData_t gameData)
{
	int free = 9;
	int retfree;
	
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(gameData.board[i][j] != ' ')
			{
				free--;
			}
		}
	}
	
	if(free > 0)
	{
		retfree = 0;
	}
	else 
	{
		retfree = 1;
	}
	
	return retfree;
}




