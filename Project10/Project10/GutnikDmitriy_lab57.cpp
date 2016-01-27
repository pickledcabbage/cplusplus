// Dmitriy Gutnik, Lab 5.7
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream inputFile;
	int number = 0;
	int sum = 0;
	int amountOfNums = 0;
	double average = 0;

	// Read in numbers from the file
	inputFile.open("Random.txt");
	while (inputFile >> number)
	{
		amountOfNums++;
		sum += number;
	}
	inputFile.close();

	// Calculate average
	average = sum*1.0 / amountOfNums;
	
	// Final display
	cout << endl << "There are " << amountOfNums << " numbers in the file." << endl;
	cout << "The sum of the numbers is " << sum << endl;
	cout << "Their average is " << average << endl;
	return 0;
}