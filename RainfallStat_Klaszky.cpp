// RainfallStats_Klaszky
//Joseph Klaszky

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Rainfall Statistics\nJoseph Klaszky\n\n" << endl;

	const int NUM_MONTHS = 12;

	double rain_fall[NUM_MONTHS], highest, lowest, average, total = 0;
	string unit_of_mes, highest_month, lowest_month, months[NUM_MONTHS] =
	{ "January", "February", "March", "April", "May", "June",
	"July", "August", "September", "October", "November", "December" };

	cout << "Are you using inches or cm:  ";
	cin >> unit_of_mes;

	for (int i = 0; i < NUM_MONTHS; i++){

		cout << "\nPlease enter the total rainfall for the month of "
			<< months[i] << ":  ";
		cin >> rain_fall[i];

		

		while (rain_fall[i] < 0){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nPlease enter a non-negative number:  ";
			cin >> rain_fall[i];
		}

		if (i == 0){
			highest = rain_fall[i];
			highest_month = months[i];
			lowest = rain_fall[i];
			lowest_month = months[i];
		}

		if (rain_fall[i] > highest){
			highest = rain_fall[i];
			highest_month = months[i];
		}

		if (rain_fall[i] < lowest){
			lowest = rain_fall[i];
			lowest_month = months[i];
		}
	}

	for (int x = 0; x < NUM_MONTHS; x++){
		total += rain_fall[x];
	}

	average = total;
	average /= 12;

	cout << fixed << showpoint << setprecision(2);
	cout << "\n\nThe total rainfall was: " << total << unit_of_mes << endl;
	cout << "The average rainfall per month was: " << average << unit_of_mes << endl;
	cout << "The month with the highest rainfall was " << highest_month << ": " << highest << unit_of_mes << endl;
	cout << "The month with the lowest rainfall was " << lowest_month << ": " << lowest << unit_of_mes << endl;

	return 0;

}
