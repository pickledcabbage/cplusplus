// Assignment 2 by Dmitriy Gutnik
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
	// Declaring variables:
	string name, address, date, cityStateZip, terms, phone, dueDate;
	string email, whoToBill, addressToBill, citySteZipToBill;
	double serviceCall, invoiceNum, subtotal, tax, paid, balanceDue, total;

	// Giving Values to strings
	name = "BayArea Locksmith";
	address = "123 S. 2nd St.";
	date = "January 26, 2014";
	cityStateZip = "San Jose, CA 95117";
	terms = "Net 0";
	phone = "(408) 213-5454";
	dueDate = "January 26, 2014";
	email = "bayarealocksmith@gmail.com";
	whoToBill = "John Doe";
	addressToBill = "325 Meridian Ave";
	citySteZipToBill = "San Jose, CA 95117";

	// Giving values to numbers
	invoiceNum = 2103;
	serviceCall = 84;
	subtotal = 84;
	tax = 0;
	paid = 84;

	// Calculations
	total = subtotal + tax;
	balanceDue = total - paid;

	// Displaying and formatting
	cout << name << "\t\tInvoice No:" << invoiceNum << endl;
	cout << address << "\t\t\tDate: " << date << endl;
	cout << cityStateZip << "\t\tTerms: " << terms << endl;
	cout << phone << "\t\t\tDue Date: " << dueDate << endl;
	cout << email << endl;
	cout << endl << endl;

	cout << "Bill to: " << whoToBill << endl;
	cout << "\t " << addressToBill << endl;
	cout << "\t " << citySteZipToBill << endl;
	cout << endl << endl << endl;

	cout << "Description\t\t\t\tAmount" << endl;
	cout << "===========\t\t\t\t======" << endl;
	cout << endl << endl;

	cout << "Service call + re key x2\t\t$" << serviceCall << ".00" << endl;
	cout << endl << endl;

	cout << "----------------------------------------------" << endl;
	cout << "Subotal\t\t\t\t\t$" << subtotal << ".00" << endl;
	cout << "Tax (8.62%)\t\t\t\t $" << tax << ".00" << endl;
	cout << "Total\t\t\t\t\t$" << total << ".00" << endl;
	cout << "Paid\t\t\t\t\t$" << paid << ".00" << endl;
	cout << "Balance Due\t\t\t\t $" << balanceDue << ".00" << endl;
	cout << endl << endl;

	// Insert breakpoint here in order to see output in command prompt.
	// Otherwise window will close after completing its run.
	return 0; 
}