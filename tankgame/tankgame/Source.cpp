#include <iostream>
#include <cstdlib>
#include <time.h>
#include <math.h>
using namespace std;

void printArr(int* arr, int length, int height, int chars[])
{
	for (int y = height; y > 0; y--)
	{
		for (int x = 0; x < length; x++)
		{
			if (x == chars[0] && arr[x] + 1 == y)
				cout << "1";
			else if (x == chars[1] && arr[x] + 1 == y)
				cout << "2";
			else if (arr[x] >= y)
				cout << "G";
			else
				cout << " ";
		}
		cout << endl;
	}
}
void fillArr(int* arr, int length, int height)
{
	srand(time(NULL));
	int random = rand() % (height / 5) + height / 4;
	int choice = 0;
	for (int i = 0; i < length; i++)
	{
		arr[i] = random;
		choice = rand() % 3;
		if (choice == 2)
			random++;
		else if (choice == 0)
			random--;
		if (random>height*4 / 7)
			random--;
		if (random < height*1 / 5)
			random++;
		//cout << choice << " ";
	}
}
int main()
{
	const int LENGTH = 60;
	const int HEIGHT = 20;
	const int GRAVITY = 7;
	int WIND = 0;
	int chars[2];
	bool done = false;
	bool playerOneTurn = true;
	chars[0] = LENGTH / 4;
	chars[1] = LENGTH / 4 * 3;
	int arr[LENGTH];
	for (int i = 0; i < LENGTH; i++)
	{
		arr[i] = HEIGHT/2;
	}
	//fillArr(&(arr[0]), LENGTH, HEIGHT);

	double power = 0;
	double angle = 0;
	int hit = -1;
	while (!done)
	{
		printArr(&(arr[0]), LENGTH, HEIGHT, chars);
		if (playerOneTurn)
			cout << "Player 1s turn." << endl;
		else
			cout << "Player 2s turn." << endl;
		srand(time(NULL));
		//WIND = rand() % 10 - 5;
		if (WIND == 0)
			cout << "WIND: NONE" << endl;
		else if (WIND < 0)
			cout << "WIND: " << WIND*(-1) << " MPH LEFT" << endl;
		else if (WIND > 0)
			cout << "WIND: " << WIND << "MPH RIGHT" << endl;
		cout << "Enter the power of your shot: ";
		cin >> power;
		cout << "Enter the angle of your shot (1-90): ";
		cin >> angle;
		int start;
		int y;
		double PI = 3.14159;
		if (playerOneTurn)
		{
			start = chars[0];
			int end = LENGTH - start;
			for (int i = 0; i < end; i++)
			{
				y = tan(angle*PI / 180.0)*power / (power + WIND)*i - 0.5*GRAVITY*i*i / (cos(angle*PI / 180.0)*cos(angle*PI / 180.0)*(power+WIND)*(power+WIND)) + arr[chars[0]] + 1;
				//cout << y << " ";

				if (arr[start + i] >= y)
				{
					arr[start + i]--;
					if (chars[1] == start + i)
					{
						done = true;
						chars[1] = -1;
					}
					i = end;
				}
			}
			//cout << endl;
		}
		else
		{
			start = chars[1];
			int end = start;
			for (int i = 0; i < end; i++)
			{
				y = tan(angle*PI / 180)*power/(power-WIND)*i - 0.5*GRAVITY*i*i / (cos(angle*PI / 180)*cos(angle*PI / 180)*(power-WIND)*(power-WIND)) + arr[chars[1]] + 1;
				//cout << y << " ";
				if (arr[start - i] >= y)
				{
					arr[start - i]--;
					if (chars[0] == start - i)
					{
						done = true;
						chars[0] = -1;
					}
						
					i = end;
				}
			}
			//cout << endl;
		}
		playerOneTurn = !playerOneTurn;
	}
	printArr(&(arr[0]), LENGTH, HEIGHT, chars);
	return 0;
}