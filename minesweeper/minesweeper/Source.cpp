#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

void printBoard(int* arr, int height, int length)
{
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
}
void printBoard2(int* arr, int* revealed, int height, int length)
{
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
}
void revealBoard(int* arr, int* revealed, int height, int length, int x, int y)
{
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
int main()
{
	const int HEIGHT = 9;
	const int LENGTH = 9;
	const int BOMBS = 10;
	int board[HEIGHT][LENGTH];
	int revealed[HEIGHT][LENGTH];

	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < LENGTH; x++)
			board[y][x] = 0;
	}
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < LENGTH; x++)
			revealed[y][x] = 0;
	}
	int x = -1;
	int y = -1;
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
	srand(time(NULL));
	for (int i = 0; i < BOMBS; i++)
	{
		int xcor = rand() % LENGTH;
		int ycor = rand() % HEIGHT;
		if (board[ycor][xcor] == 0 && (ycor != y || xcor != x))
			board[ycor][xcor] = 9;
		else
			i--;
	}

	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < LENGTH; x++)
		{
			int counter = 0;
			if (board[y][x] != 9)
			{
				if (x > 0 && board[y][x - 1] == 9)
					counter++;
				if (x < LENGTH - 1 && board[y][x + 1] == 9)
					counter++;
				if (y > 0 && board[y - 1][x] == 9)
					counter++;
				if (y < HEIGHT - 1 && board[y + 1][x] == 9)
					counter++;
				if (x > 0 && y > 0 && board[y - 1][x - 1] == 9)
					counter++;
				if (x < LENGTH - 1 && y < HEIGHT - 1 && board[y + 1][x + 1] == 9)
					counter++;
				if (x < LENGTH - 1 && y > 0 && board[y - 1][x + 1] == 9)
					counter++;
				if (x > 0 && y < HEIGHT - 1 && board[y + 1][x - 1] == 9)
					counter++;
				board[y][x] = counter;
			}
		}
	}

	revealBoard(&(board[0][0]), &(revealed[0][0]), HEIGHT, LENGTH, x, y);
	bool done = false;
	bool win = false;
	while (!done)
	{
		x= -1;
		y = -1;
		printBoard2(&(board[0][0]),&(revealed[0][0]), HEIGHT, LENGTH);
		while (x < 0 || x > LENGTH-1)
		{
			cout << "Enter the x coordinate where you want to explore (0 - " << LENGTH - 1 << "): ";
			cin >> x;
		}
		while (y < 0 || y > HEIGHT - 1)
		{
			cout << "Enter the y coordinate where you want to explore (0 - " << HEIGHT - 1 << "): ";
			cin >> y;
		}
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