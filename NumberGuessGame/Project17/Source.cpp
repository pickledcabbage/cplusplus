#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int main()
{
	int number;
	int guesses = 0;
	cout << "I thought of a number (1-100)..." << endl;
	srand(time(NULL));
	number = rand() % 100 + 1;
	while (number > 0)
	{
		guesses++;
		int temp;
		cout << "Enter the number for guess " << guesses << ": ";
		cin >> temp;
		if (temp == number)
			number = -1;
		else if (number > temp)
			cout << "My number is GREATER than yours." << endl;
		else if (number < temp)
			cout << "My number is LESS than yours." << endl;
	}
	cout << "You got the number in " << guesses << "guess(es)!" << endl;
	cin.get();

	return 0;
}