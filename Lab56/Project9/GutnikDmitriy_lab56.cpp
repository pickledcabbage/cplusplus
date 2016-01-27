// Dmitriy Gutnik, Lab 5.6
#include <iostream>
using namespace std;

int main()
{
	int years;
	double sum = 0, average = 0, rainfall = 0;
	// Prompt for years
	cout << "Enter the amount of years: ";
	cin >> years;

	//Loop for continuous prompting
	for (int i = 0; i < years; i++)
	{
		for (int month = 1; month <= 12; month++)
		{
			cout << "Enter the rainfall for month " << month+i*12 << " : ";
			cin >> rainfall;
			sum += rainfall;
			if (rainfall < 0)
			{
				month = -1;
				years = -1;
			}
				
		}
	}
	// Calculates average
	average = sum / (years * 12);

	// Final display
	if (years <= 0)
	{
		cout << endl << "Input Validation: Do not accept a number less than 1 for the number of years. Do not accept negative numbers for the monthly rainfall." << endl;
	}
	else
	{
		cout << endl << "The number of months you enter was " << years * 12 << endl;
		cout << "The total inches of rainfall was " << sum << endl;
		cout << "The average inches of rainfall was " << average << endl;
	}
	return 0;
}