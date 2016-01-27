// Dmitriy Gutnik, Assignment 9
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int arr1[19];
	int arr2[19];
	ifstream inputFile;
	inputFile.open("Payroll.txt");
	int number = 0, salary = 0;
	int i = 0;

	// Scans file into 2 arrays
	while (inputFile >> number)
	{
		arr1[i] = number;
		inputFile.ignore();
		inputFile >> number;
		arr2[i] = number;
		i++;
	}

	// Gets input from user and gets according salary.
	cout << "Enter a payroll number (0 or negtive to close): ";
	cin >> number;
	if (number > 0)
	{
		for (int c = 0; c < 19; c++)
		{
			if (arr1[c] == number)
				salary = arr2[c];
		}
		if (salary != 0)
			cout << "The salary associated with your payroll is: " << salary;
		else
			cout << "Your payroll code was not found.";
	}
	return 0;
}