/*
 * TimeClock.cpp
 *
 *  Created on: Jul 12, 2020
 *      Author: Kyle Gaskill
 */
#include <iostream>
#include <ctime>
#include <iomanip>
#include <ios>
#include <stdlib.h>


using namespace std;

//time_t to current_time variable
time_t current_time = time(NULL);
tm *tm_local = localtime(&current_time);

//12 hour adjustable variables
int timeHour12;
int timeMinute12 = tm_local->tm_min;
int timeSeconds12 = tm_local->tm_sec;
string amPm;

//24 hour adjustable variables
int timeHour24 = tm_local->tm_hour;
int timeMinute24 = tm_local->tm_min;
int timeSecond24 = tm_local->tm_sec;


// Converts 24 to 12 and displays;
void DisplayTime() {


	// if else else if to convert 24 hours to 12 hour time
	if (timeHour24 == 0 && timeHour24 != 12)  {
		timeHour12 = 12;
	}

	else if (timeHour24 == 12 && timeHour24 != 0)  {
		timeHour12 = 12;

	}

	else if (timeHour24 < 12 && timeHour24 !=0) {
		timeHour12 = timeHour24;
	}

	else if (timeHour24 > 12 && timeHour24 != 0)  {
		timeHour12 = timeHour24 - 12;
	}


	if (timeHour24 <= 11)  {
		amPm = "A M";
	}

	else {
		amPm = "P M";
	}


	//Asterisk fill for time clock
	cout << setfill('*') << setw(27) << "";           //12 hour cover
	cout << setfill(' ') << setw(8) << "";
	cout << setfill('*') << setw(27) << "" << endl;   //24 clock cover

	cout << "*" << "      12-Hour Clock" << "      *";
	cout << "        *      24-Hour Clock" << "      *" << endl;

	// 12 hour time
	cout << "*" << "       ";
	printf("%02d", timeHour12);
	cout << ":";
	printf("%02d", timeMinute12);
	cout << ":";
	printf("%02d", timeSeconds12);
	cout << " " << amPm << "      *";

	//24 hour time
	cout << "        *        ";
	printf("%02d", timeHour24);

	cout << ":";
	printf("%02d", timeMinute24);
	cout << ":";
	printf("%02d", timeSecond24);
	cout << "         *" << endl;

	//bottom of clock box
	cout << setfill('*') << setw(27) << "";
	cout << setfill(' ') << setw(8) << "";
	cout << setfill('*') << setw(27) << "" << endl;


}

//Display menu to change time
void DisplayMenu() {

	//top cover of menu
	cout << "\n**************************" << endl;
	cout << "* 1 - Add One Hour" << setfill(' ') << setw(8) << right << "*" << endl;
	cout << "* 2 - Add One Minute" << setfill(' ') << setw(6) << right << "*" << endl;
	cout << "* 3 - Add One Second" << setfill(' ') << setw(6) << right << "*" << endl;
	cout << "* 4 - Exit Program" << setfill(' ') << setw(8) << right << "*" << endl;
	cout << "**************************" << endl;

}


// Add one hour to clocks
void AddHour() {
	if(timeHour12 == 11)  {
		timeHour12 = 12;
		if (amPm == "A M")  {
			amPm = "P M";
		}

		else if(timeHour12 == 11 && amPm == "P M")  {

			amPm = "A M";
		}

	}

	else  {
		timeHour12 += 1;

	}

	if(timeHour24 == 23)  {
		timeHour24 = 00;


	}

	else  {
		timeHour24 += 1;

	}

}

// Add one minute to clocks
void AddMinute()  {

	//if loop to change hour if minute is 59
	if(timeMinute12 == 59)  {
		timeMinute12 = 00;
		AddHour();
	}

	else {
		timeMinute12 += 1;
	}

	//if loop to change hour if minute is 59
	if(timeMinute24 == 59)  {
		timeMinute24 = 00;
		AddHour();
	}

	else  {
		timeMinute24 += 1;
	}
}

// Add one second to clocks
void AddSecond()  {
	// if loop to change minute if second is 59
	if(timeSeconds12 == 59) {
		timeSeconds12 = 00;
		AddMinute();
	}

	else {
		timeSeconds12 += 1;
	}

	// if loop to change minute if second is 59
	if(timeSecond24 == 59)  {
		timeSecond24 = 00;
		AddMinute();
	}

	else {
		timeSecond24 += 1;
	}

}

// Clear screen function
void clrscr()
{
    system("@cls||clear");
}



int main() {

	// input variable for Do while loop
	int userInput;

	do  {
	clrscr();
	DisplayTime();
	DisplayMenu();

	cin >> userInput;

	switch (userInput)  {
	case 1:
		AddHour();
		break;

	case 2:
		AddMinute();
		break;


	case 3:
		AddSecond();
		break;

	case 4:
		cout << "Goodbye.";

		break;

	default:
		cout << "Not a valid choice." << endl;
		break;
	}

	} while (userInput != 4);


	return 0;
}

