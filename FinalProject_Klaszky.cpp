// FinalProject_Klaszky.cpp 
//Joseph Klaszky

#include "stdafx.h"
#include <iostream>


// ######### Prototypes ###########
void fill_chart();
void display_chart();
void list_seats();
void seat_bought();
int menu();

using namespace std;

// ####### Global Variables #######
const int ROWS = 15, COLS = 30;
int menu_choice, row_input, col_input;
char seat_empty = '#', seat_full = '*', seats[ROWS][COLS];




int _tmain(int argc, _TCHAR* argv[])
{

	//Project info
	cout << "Final Project" << endl;
	cout << "Joseph Klaszky\n\n" << endl;

	//Initial seating chart set up
	fill_chart();

	//Welcome Message
	cout << "Welcome to the 'Theatre of the Living Arts' ticket reservation system." << endl;
	cout << "\nBelow you will see a seating chart of the seats that are still availible." << endl;

	display_chart();
	
	//Main system loop
	do
	{
		//Runs menu function and sets user's choice to the var menu_choice to be checked by the while statment
		menu_choice = menu();

		if (menu_choice == 1)
		{
			display_chart();
		}

		else if (menu_choice == 2) 
		{
			list_seats();
		}


		else if (menu_choice == 3)
		{
			seat_bought();
			cout << "\nThank you so much! We will save your seat." << endl;
		}

	} 

	while (menu_choice != 0);


	return 0;
}


void fill_chart()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int x = 0; x < COLS; x++)
		{
			seats[i][x] = seat_empty;
		}
	}
}

void display_chart()
{
	//The display is a little funky looking but I think it gets its point across
	cout << "\nColumns:          1 1 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 2 2 3" << endl;
	cout <<   "1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0" << endl;

	for (int i = 0; i < ROWS; i++)
	{
		for (int x = 0; x < COLS; x++)
		{
			cout << seats[i][x] << ' ';
		}
		
		cout << "Row " << (i + 1) << endl;
	}

}

void list_seats()
{
	cout << "Seats available: " << endl;
	for (int i = 0; i < ROWS; i++)
	{
		cout << "Row " << i+1 << " seats: ";
		for (int x = 0; x < COLS; x++)
		{

			if (seats[i][x] == seat_empty)
			{
				cout << x+1 << " ";
			}
			
		}

		cout << "\n" << endl;
	}
}

void seat_bought()
{
	int counter = 0;
	do
	{
		//If it is the second time through the loop that means the user tried to buy a seat that was already filled
		//so this if apologizes and makes them try again.
		if (counter >= 1)
		{
			cout << "Sorry that seat is already filled. Please try again." << endl;
		}

		cout << "\n\nPlease enter the Row (1-15) of the seat you would like to buy: ";
		cin >> row_input;

		cout << "\n\nPlease enter the Column (1-30) of the seat you would like to buy: ";
		cin >> col_input;

		//The arrays start at 0 so to make it line up I had to decrement my variables
		--row_input;
		--col_input;

		while ((row_input < 0 || row_input > 14) || (col_input < 0 || col_input > 29))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "\n\nSorry I didn't understand that. Please try again." << endl;

			cout << "\nPlease enter the Row (1-15) of the seat you would like to buy : ";
			cin >> row_input;

			cout << "\nPlease enter the Column (1-30) of the seat you would like to buy : ";
			cin >> col_input;

		}

		counter += 1;
	} while (seats[row_input][col_input] == seat_full);

	seats[row_input][col_input] = seat_full;
}

int menu()
{	
	int choice;

	cout << "\n\n    ############### Menu ###############\n\n" << endl;
	cout << "Please select from the menu what you would like to do:" << endl;
	cout << "\n1. Display seating chart." << endl;
	cout << "2. List the seats availivble." << endl;
	cout << "3. Buy a ticket."<< endl;
	cout << "0. Exit menu and close.\n" << endl;
	cin >> choice;
	
	while (choice < 0 || choice > 3)
	{
		
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "\nSorry I didn't understand that. Please make a selection from the menu: ";
		cin >> choice;
	}

	return choice;
}
