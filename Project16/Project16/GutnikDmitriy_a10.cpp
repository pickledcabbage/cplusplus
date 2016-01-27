// Dmitriy Gutnik, Assignment 10
#include <iostream>
#include <iomanip>
using namespace std;

double getAmountSold()
{
	// FUnction that gets input amount from user
	double temp;
	cout << "Enter the price of your sale (Negative values or 0 to stop): ";
	cin >> temp;
	return temp;
}
void calcCommission(double &amount)
{
	// FUnction that changes amount to commission
	amount *= 0.1;
}
void displayCommission(double &amount)
{
	// Function that dsiplays the commission and calls calcCOmmission()
	double temp = amount;
	calcCommission(amount);
	cout << setprecision(2) << fixed << "The commission for $" << temp << " is: $" << amount << endl;
}
void totalCommission()
{
	// The main loop of the program that calculates total commission
	double totalCom = 0;
	bool sentinel = true;
	while (sentinel)
	{
		double amount = getAmountSold();
		if (amount <= 0)
		{
			sentinel = false;
			amount = 0;
		}
		else
			displayCommission(amount);
		totalCom += amount;
	}
	cout << endl << setprecision(2) << fixed << "The total commission for your sales is: $" << totalCom;
}
int main()
{
	totalCommission();
	return 0;
}