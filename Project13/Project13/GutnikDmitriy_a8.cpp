// Dmitriy Gutnik, Assignment 8
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double salary = 0;

	// Just two loops in this program, first one prompts for salary second one does display
	do
	{
		cout << "Salary (negative number or 0 to end): ";
		cin >> salary;
		cout << setprecision(2) << fixed;
		if (salary > 0)
		{
			for (double i = 0.03; i <= 0.06; i += 0.01)
			{
				cout << "Raise rate: " << static_cast<int>(i * 100) << "%" << endl;
				cout << "Year 1:   Raise: $" << salary*i << endl;
				cout << "Year 2:   Raise: $" << salary*i*(1+i) << endl;
				cout << "Year 3:   Raise: $" << salary*i*(1+i)*(1+i) << endl << endl;
			}
		}
	} while (salary > 0);
	return 0;
}