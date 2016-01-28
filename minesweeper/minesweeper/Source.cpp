#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

void printBoard(int* arr, int height, int length)
{
	cout << endl;
	cout << "   ";
	for (int i = 0; i < length; i++)
		cout << i;
	cout << endl;
	cout << "   ";
	for (int i = 0; i < length; i++)
		cout << "_";
	cout << endl;
	for (int y = 0; y < height; y++)
	{
		cout << y << " |";
		for (int x = 0; x < length; x++)
		{
			if (arr[y*length + x] == 9)
				cout << "B";
			else if (arr[y*length + x] > 0)
				cout << arr[y*length + x];
			else
				cout << " ";
		}
		cout << "|" << endl;
	}
	cout << endl;
}
void printBoard2(int* arr, int* revealed, int height, int length)
{
	cout << endl;
	cout << "   ";
	for (int i = 0; i < length; i++)
		cout << i;
	cout << endl;
	cout << "   ";
	for (int i = 0; i < length; i++)
		cout << "_";
	cout << endl;
	for (int y = 0; y < height; y++)
	{
		cout << y << " |";
		for (int x = 0; x < length; x++)
		{
			if (revealed[y*length + x] == 1)
			{
				if (arr[y*length + x] == 9)
					cout << "B";
				else if (arr[y*length + x] > 0)
					cout << arr[y*length + x];
				else
					cout << " ";
			}
			else
				cout << "X";
		}
		cout << "|"<< endl;
	}
	cout << endl;
}
void revealBoard(int* arr, int* revealed, int height, int length, int x, int y)
{
	// SPOT (X,Y) IS TRYING TO BE EXPLORED, REVEAL BOARD BASED AROUND THAT.
	if (arr[y*length + x] > 0)
		revealed[y*length + x] = 1;
	else
	{
		revealed[y*length + x] = 1;
		if (x > 0 && revealed[(y)*length+x-1] == 0)
			revealBoard(&(arr[0]), &(revealed[0]), height, length, x-1, y);

		if (x < length - 1 && revealed[(y)*length + x+1] == 0)
			revealBoard(&(arr[0]), &(revealed[0]), height, length, x+1, y);

		if (y > 0 && revealed[(y-1)*length + x] == 0)
			revealBoard(&(arr[0]), &(revealed[0]), height, length, x, y-1);

		if (y < height - 1 && revealed[(y+1)*length + x] == 0)
			revealBoard(&(arr[0]), &(revealed[0]), height, length, x, y+1);

		if (x > 0 && y > 0 && revealed[(y-1)*length + x-1] == 0)
			revealBoard(&(arr[0]), &(revealed[0]), height, length, x-1, y-1);

		if (x < length - 1 && y < height - 1 && revealed[(y+1)*length + x+1] == 0)
			revealBoard(&(arr[0]), &(revealed[0]), height, length, x+1, y+1);

		if (x < length - 1 && y > 0 && revealed[(y-1)*length + x+1] == 0)
			revealBoard(&(arr[0]), &(revealed[0]), height, length, x+1, y-1);

		if (x > 0 && y < height - 1 && revealed[(y+1)*length + x-1] == 0)
			revealBoard(&(arr[0]), &(revealed[0]), height, length, x-1, y+1);
	}
}
bool check(int* arr, int height, int length, int bombs)
{
	// CHECKS NUMBER OF BOMBS POPPED
	int counter = 0;
	for (int i = 0; i < height*length; i++)
	{
		if (arr[i] == 0)
		{
			counter++;
		}

	}
	return (counter == bombs);
}
void getXandY(int& x, int& y, int HEIGHT, int LENGTH)
{

	while (x < 0 || x > LENGTH - 1)
	{
		cout << "Enter the x coordinate where you want to explore (0 - " << LENGTH - 1 << "): ";
		cin >> x;
	}
	while (y < 0 || y > HEIGHT - 1)
	{
		cout << "Enter the y coordinate where you want to explore (0 - " << HEIGHT - 1 << "): ";
		cin >> y;
	}
}
void makeNewGame(int* b, int* r, int HEIGHT, int LENGTH)
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < LENGTH; x++)
			b[y*LENGTH+x] = 0;
	}
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < LENGTH; x++)
			r[y*LENGTH+x] = 0;
	}
	printBoard2(b, r, HEIGHT, LENGTH);
}
void setUpBoard(int* board, int* revealed, int HEIGHT, int LENGTH, int BOMBS)
{
	int x = -1;
	int y = -1;
	getXandY(x, y, HEIGHT, LENGTH);
	srand(time(NULL));
	for (int i = 0; i < BOMBS; i++)
	{
		int xcor = rand() % LENGTH;
		int ycor = rand() % HEIGHT;
		if (board[ycor*LENGTH+xcor] == 0 && (ycor != y || xcor != x))
			board[ycor*LENGTH+xcor] = 9;
		else
			i--;
	}

	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < LENGTH; x++)
		{
			int counter = 0;
			if (board[y*LENGTH+x] != 9)
			{
				if (x > 0 && board[y*LENGTH+(x - 1)] == 9)
					counter++;
				if (x < LENGTH - 1 && board[y*LENGTH+(x + 1)] == 9)
					counter++;
				if (y > 0 && board[(y - 1)*LENGTH+x] == 9)
					counter++;
				if (y < HEIGHT - 1 && board[(y + 1)*LENGTH+x] == 9)
					counter++;
				if (x > 0 && y > 0 && board[(y - 1)*LENGTH+(x - 1)] == 9)
					counter++;
				if (x < LENGTH - 1 && y < HEIGHT - 1 && board[(y + 1)*LENGTH + x + 1] == 9)
					counter++;
				if (x < LENGTH - 1 && y > 0 && board[(y - 1)*LENGTH + x + 1] == 9)
					counter++;
				if (x > 0 && y < HEIGHT - 1 && board[(y + 1)*LENGTH + x - 1] == 9)
					counter++;
				board[y*LENGTH+x] = counter;
			}
		}
	}
	revealBoard(&(board[0]), &(revealed[0]), HEIGHT, LENGTH, x, y);
}
int main()
{
	const int HEIGHT = 9;
	const int LENGTH = 9;
	const int BOMBS = 10;
	int board[HEIGHT][LENGTH];
	int revealed[HEIGHT][LENGTH];

	makeNewGame(&board[0][0], &revealed[0][0], HEIGHT, LENGTH);
	setUpBoard(&board[0][0], &revealed[0][0],HEIGHT, LENGTH, BOMBS);
	
	bool done = false;
	bool win = false;
	while (!done)
	{
		int x= -1;
		int y = -1;
		printBoard2(&(board[0][0]),&(revealed[0][0]), HEIGHT, LENGTH);
		getXandY(x, y, HEIGHT, LENGTH);
		revealBoard(&(board[0][0]), &(revealed[0][0]), HEIGHT, LENGTH, x, y);
		if (check(&(revealed[0][0]), HEIGHT, LENGTH, BOMBS))
		{
			done = true;
			win = true;
		}
		if (board[y][x] == 9)
		{
			done = true;
			win = false;
		}
	}
	if (!win)
	{
		printBoard2(&(board[0][0]), &(revealed[0][0]), HEIGHT, LENGTH);
		cout << endl << "YOU STEPPED ON A MINE! YOU LOSE!";
	}
	else
	{
		printBoard(&(board[0][0]), HEIGHT, LENGTH);
		cout << endl << "YOU GOT PASSED ALL THE MINES! YOU WIN!";
	}

	return 0;
}