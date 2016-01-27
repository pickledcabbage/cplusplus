// Dmitriy Gutnik
// Assignment 3
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	const int ORCH_PRICE = 25, MF_PRICE = 30, BAL_PRICE = 15;
	int orchSold, mfSold, balSold, orchRev, mfRev, balRev, totalRev;
	double orchPer, balPer, mfPer;

	// Prompts for user inputs
	cout << "How many orchestra seats were sold: ";
	cin >> orchSold;
	cout << "How many main floor seats were sold: ";
	cin >> mfSold;
	cout << "How many balcony seats were sold: ";
	cin >> balSold;

	// Calculations to get display variables
	orchRev = orchSold*ORCH_PRICE;
	mfRev = mfSold*MF_PRICE;
	balRev = balSold*BAL_PRICE;
	totalRev = orchRev + mfRev + balRev;
	orchPer = orchRev*100.0 / totalRev;
	mfPer = mfRev*100.0 / totalRev;
	balPer = balRev*100.0 / totalRev;

	// Final formatted output
	cout << endl << endl << setprecision(2) << fixed;
	cout << "Revenue from each seating followed by percent of total:" << endl;
	cout << "Orchestra:  $" << setw(7) << orchRev << " " << setw(4) << orchPer << "%" << endl;
	cout << "Main Floor: $" << setw(7) <<   mfRev << " " << setw(4) <<   mfPer << "%" << endl;
	cout << "Balcony:    $" << setw(7) <<  balRev << " " << setw(4) <<  balPer << "%" << endl;
	cout << "Total:      $" << setw(7) << totalRev;
	return 0;
}