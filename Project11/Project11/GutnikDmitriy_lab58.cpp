#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	// Open files for operations
	ifstream inputFile;
	ofstream outputFile;
	inputFile.open("Input.txt");
	outputFile.open("Output.txt");

	// Get number from input and if it is even add to output
	int number;
	while (inputFile >> number)
	{
		if (number % 2 == 0)
			outputFile << number << endl;
	}

	// Close files
	inputFile.close();
	outputFile.close();
	return 0;
}