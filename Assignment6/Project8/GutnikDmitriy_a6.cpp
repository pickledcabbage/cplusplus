// Dmitriy Gutnik, Assignment 6
#include <iostream>
using namespace std;

int main()
{
	int first = 0, second = 0, finalVal = 0;
	char operation;
	bool valid = true;

	// Getting input from user
	cout << "Enter the type of operation: ";
	cin >> operation;
	if (operation != 'A' && operation != 'a' && operation != 'S' && operation != 's' && operation != 'D' && operation != 'd' && operation != 'M' && operation != 'm')
		valid = false;
	if (valid)
	{
		cout << "Enter the first integer: ";
		cin >> first;
		cout << "Enter the second integer: ";
		cin >> second;
	}

	// Flipping if the second integer is greater than the first
	if (first < second)
	{
		int temp = first;
		first = second;
		second = temp;
	}

	// Doing the desired operation
	switch (operation)
	{
		case'a':
		case'A': finalVal = first + second; break;
		case's':
		case'S': finalVal = first - second; break;
		case'm': 
		case'M': finalVal = first * second; break;
		case'd': 
		case'D': finalVal = first / second; break;
	}

	// Final display
	if (valid)
		cout << endl << "The final answer is " << finalVal;
	else
		cout << endl << "Please enter a valid letter for the operation: A,a,S,s,M,m,D,d";
	return 0;
}