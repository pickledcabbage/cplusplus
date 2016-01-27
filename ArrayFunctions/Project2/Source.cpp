#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

void fillWithRand(short* arr, short length);
void fillWithZeros(short* arr, short length);
void printArr(short* arr, short length);
int main()
{
	short const ARR_LENGTH = 100;
	short board[ARR_LENGTH];
	fillWithRand(&(board[0]), ARR_LENGTH);
	printArr(&(board[0]), ARR_LENGTH);
	return 0;
}
void printArr(short* arr, short length)
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << "\t";
		/*if ((i+1) % 20 == 0)
		{
			cout << endl;
		}*/
	}
}
void fillWithRand(short* arr, short length)
{
	srand(time(NULL));
	for (int i = 0; i < length; i++)
	{
		arr[i] = rand()%99+1;
	}
}
void fillWithZeros(short* arr, short length)
{
	for (int i = 0; i < length; i++)
	{
		arr[i] = 0;
	}
}