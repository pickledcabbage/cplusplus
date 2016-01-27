// Dmitriy Gutnik, Assignment 7
#include <iostream>
using namespace std;

int main()
{
	int number = 0;
	int sum = 0;
	
	// Loop for incomes
	do
	{
		cout << "Income amount (negative number to end): ";
		cin >> number;
		if (number > 0)
			sum += number;
	} while (number > 0);

	// Loop for expenses
	do
	{
		cout << "Expense amount (negative number to end): ";
		cin >> number;
		if (number > 0)
			sum -= number;
	} while (number > 0);

	// Display proper final output
	if (sum > 0)
		cout << "Profit: $" << sum;
	else
		cout << "Loss: $" << sum*(-1);
	return 0;
}