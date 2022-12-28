/*
* Kurt Kangas
* CIS 1202 C++ Programming II
* Week 8 Project
* Warehouse Inventory System
*/

#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <fstream>

using namespace std;

const int SIZE = 100, N_SIZE = 51;
struct Product_S
{
	int productID;
	char productName[N_SIZE];
	double productPrice;
};

Product_S EnterData(Product_S[]);
Product_S EnterProduct(Product_S[], vector<int>);


int main()
{
	cout << setprecision(2) << fixed;

	const int SIZE = 100;
	Product_S ProductArray[SIZE];
	vector<int> orderedId;
	int counter = 0;
	int choice = 0;
	int selection;

	cout << "\tWarehouse Inventory\n";
	string j[] = { "Name: ", "Price: $" };
	string line, line2;
	ifstream myfile("WarehouseInventory.txt");
	if (myfile.is_open())
	{
		int x = 0;
		while (getline(myfile, line))
		{
			cout << "Product " << j[x];
			cout << line << '\n';
			x++;
			if (x == 2)
			{
				x = 0;
			}
		}
		myfile.close();
	}
	else cout << "Unable to open file";

	cout << endl;



	bool notValid = true;

	while (notValid)
	{
		int choice;
		notValid = false;
		cout << "1. Enter a new product";
		cout << "\n2. Exit the program";
		cout << "\n...";
		cin >> choice;
		if (choice < 1 || choice > 2)
		{
			cout << "Not a valid choice.\n";
			notValid = true;
		}
		else
		{
			selection = choice;
		}
	}
	char again = 'b';
	do
	{
		if (selection == 1)
		{
			EnterData(ProductArray);
			counter++;

			cout << "Do you want to enter another product? 'y' or 'n': ";
			cin >> again;
			if (again == 'y')
			{
				selection == 1;
			}
			else
			{
				selection = 2;
			}
		}
	} while (selection != 2 && again != 'n');

	cout << "\n\tCurrent/Updated Warehouse Inventory\n";
	myfile.open("WarehouseInventory.txt");
	if (myfile.is_open())
	{
		int x = 0;
		while (getline(myfile, line))
		{
			cout << "Product " << j[x];
			cout << line << '\n';
			x++;
			if (x == 2)
			{
				x = 0;
			}
		}
		myfile.close();
	}
	else cout << "Unable to open file";

	cout << endl << endl;
	system("pause");
	return 0;
}

Product_S EnterData(Product_S Array1[])
{
	int counter = 0;
	Product_S Array2;
	// Enter IDs , function call
	cout << "Enter the product name>";
	cin.ignore();   //Used if a getline is before this.
	cin.get(Array2.productName, N_SIZE);
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	counter++;
	cout << "Enter the product retail price>";
	cin >> Array2.productPrice;
	counter++;

	fstream myfile("WarehouseInventory.txt", ios::out | ios::app);
	if (myfile.is_open())
	{
		myfile << Array2.productName << endl;
		myfile << Array2.productPrice << endl;
		myfile.close();
	}
	else cout << "Unable to open file";

	return Array2;
}
