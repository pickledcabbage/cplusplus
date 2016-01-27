#include <iostream>
#include <math.h>
#include <cstdlib>
#include <time.h>
using namespace std;

void makeBlank(int* board, int height, int width);
void makeTerrain(int* board, int height, int width);
void printBoard(int* board, int height, int width);
int main()
{
	const int MAP_HEIGHT = 40;
	const int MAP_WIDTH = 40;
	int x1, y1, x2, y2;
	int board[MAP_HEIGHT*MAP_WIDTH+4];
	makeBlank(&(board[0]), MAP_HEIGHT, MAP_WIDTH);
	makeTerrain(&(board[0]), MAP_HEIGHT, MAP_WIDTH);
	
	srand(time(NULL));
	x1 = 6 + rand() % 10;
	y1 = 19;
	x2 = 26 + rand() % 10;
	y2 = 19;
	board[y1*MAP_WIDTH + x1] = 3;
	board[y2*MAP_WIDTH + x2] = 4;
	printBoard(&(board[0]), MAP_HEIGHT, MAP_WIDTH);
	int angle, strength;
	cout << "Enter the strength of your shot (1-20):";
	cin >> strength;
	cout << "Enter the angle of your shot (1-90):";
	cin >> angle;


	
	return 0;
}
void makeBlank(int* board, int height, int width)
{
	for (int i = 0; i < height*width; i++)
	{
		board[i] = 0;
	}
}
void calcHit(int* board, int height, int width)
{
	int angle, strength;
	cout << "Enter the strength of your shot (1-20):";
	cin >> strength;
	cout << "Enter the angle of your shot (1-90):";
	cin >> angle;

}
void makeTerrain(int* board, int height, int width)
{
	for (int y = height/2; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			board[y*width + x] = 1;
		}
	}
}
void printBoard(int* board, int height, int width)
{
	for (int i = 0; i < height*width; i++)
	{
		if (board[i] == 3)
			cout << "A";
		else if (board[i] == 4)
			cout << "B";
		else
			cout << board[i];
		if ((i+1)%width==0)
		{
			cout << endl;
		}
	}
}