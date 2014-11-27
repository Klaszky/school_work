#include<vector>
#include<iostream>
#include<string>

using namespace std;

int main(){

	const int NUM_MONTHS = 12;
	
	double rain_fall[NUM_MONTHS], highest, lowest average, total; 
	string highest_month, lowest_month, months[NUM_MONTHS] = 
	{"January", "February", "March", "April", "May", "June",
	"July", "August", "September", "October", "November", "December"};

	for(int i=0; i < NUM_MONTHS; i++){
		
		cout << "Please enter the total rainfall for the month of "
		<< months[i] << ": " << endl;
		cin << rain_fall[i];
		
		while (rain_fall < 0){
			cout << "Please enter a non-negative number: " << endl;
			cin << rain_fall[i];
		}

		if(i == 0){
			highest = rain_fall[i];
			highest_month = months[i];
			lowest = rain_fall[i];
			lowest_month = months[i];
		}
		
		if(rain_fall[i] > highest){
			highest = rain_fall[i];
			highest_month = months[i];
		}
		
		if(rain_fall[i] < lowest){
			lowest = rain_fall[i];
			lowest_month = months[i];
		}
	}

	for(int x = 0; x < NUM_MONTHS; x++){
		total += rain_fall[i];
	}

	average /= 12;

	cout << "The total rainfall was: " << total << endl;
	cout << "The average rainfall per month was: " << average << endl;
	cout << "The month with the highest rainfall was: " << highest << endl;
	cout << "The month with the lowest rainfall was: " << lowest << endl;





	return 0;
}