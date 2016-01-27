// Dmitriy Gutnik Assignment 4
#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
using namespace std;

int main()
{
	string first, last, address, city, state, zip;
	int lotto1, lotto2, lotto3, lotto4, lotto5, mega;
	srand(time(NULL));

	// First set of prompts
	cout << "Enter your first name: ";
	getline(cin, first);
	cout << "Enter your last name: ";
	getline(cin, last);
	cout << "Enter your address: ";
	getline(cin, address);
	cout << "Enter your city: ";
	getline(cin, city);
	cout << "Enter your state in 2 letter format: ";
	getline(cin, state);
	cout << "Enter your zip code: ";
	getline(cin, zip);
	cout << endl;

	// Calculates random numbers for lotto
	lotto1 = 1 + rand() % 75;
	lotto2 = 1 + rand() % 75;
	lotto3 = 1 + rand() % 75;
	lotto4 = 1 + rand() % 75;
	lotto5 = 1 + rand() % 75;
	mega = 1 + rand() % 15;

	// Final formatted output
	cout << first << " " << last << endl;
	cout << address << endl;
	cout << city << ", " << state << " " << zip << endl << endl;
	cout << "The lotto numbers for Mega Millions are:" << endl;
	cout << lotto1 << " " << lotto2 << " " << lotto3 << " " << lotto4 << " " << lotto5 << endl;
	cout << "Mega: " << mega;
	return 0;
}