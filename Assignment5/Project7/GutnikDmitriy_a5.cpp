// Dmitriy Gutnik, Assignemnt 5
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	float start = 0;
	float minutes = 0;
	float rate = 0;
	float charge = 0;
	bool valid = true;

	// Getting data from user
	cout << "Enter the start time of your call: ";
	cin >> start;
	if ((start < 0 || start >= 23.6)||((start - static_cast<int>(start)) >= 0.6))
		valid = false;
	else
	{
		cout << "Enter the amount of minutes: ";
		cin >> minutes;
	}

	// Calculating charge rate
	if (start >= 0 && start <= 6.59)
		rate = 0.12;
	else if (start >= 7 && start <= 19)
		rate = 0.55;
	else if (start >= 19.01 && start <= 23.6)
		rate = 0.35;
	charge = rate*minutes;

	// Final display
	if (valid)
		cout << "The charge for the telephone call is: $" << setw(4) << setprecision(2) << fixed << charge;
	else
		cout << "Input Validation: The program should not accept times that are greater than 23:59. Also, no number whose last two digits are greater than 59 should be accepted. ";
	return 0;
}