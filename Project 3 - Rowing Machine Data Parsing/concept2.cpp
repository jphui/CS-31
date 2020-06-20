#include <iostream>
using namespace std;
#include <string>
#include <cassert>
#include <cctype>

int number(string s, int& startingposition);
bool isValidRowerString(string rowerString);
int totalDistance(string rowerString);
int heartRate(string rowerString);
int strokesPerMinute(string rowerString);
int elapsedMinutes(string rowerString);
int elapsedSeconds(string rowerString);

int numberX(string s, int& startingposition);

string pullNums(string old);

int retNum(string s, int numSpaces);


int main()
{
	
	string s;
	cout.setf(ios::boolalpha);

	for (;;)
	{
		cout << "Enter rower string: ";
		getline(cin, s);
		if (s == "quit") break;
		cout << "isValidRowerString returns ";
		cout << isValidRowerString(s) << endl;
		
		cout << "totalDistance(s) returns ";
		cout << totalDistance(s) << endl;
		cout << "heartRate(s) returns ";
		cout << heartRate(s) << endl;
		cout << "elapsedMinutes(s) returns ";
		cout << elapsedMinutes(s) << endl;
		cout << "elapsedSeconds(s) returns ";
		cout << elapsedSeconds(s) << endl;
		
		cout << pullNums(s) << endl;
	}
	






	/*
	assert( ! isValidRowerString("UA1+1"));
	assert( ! isValidRowerString("    "));
	cerr << "All tests succeeded" << endl;
	*/

	return 0;
}


bool isValidRowerString(string rowerString)
{
	bool minutesPresent = true;

	int index = 0;
	int temp = number(rowerString, index);
	if (temp < 1)
	{
		//cerr << endl << "index: " << index;
		if (rowerString[index] != ':')
		{
			cerr << endl << "char instead of colon: " << rowerString[index] << endl;
			return false;
		}

		//this code runs if there are no minutes but a colon is present
		//if this is the case, then the statement that checks minutes will cause issues and you need to skip it

		//cerr << endl << "no minutes" << endl;
		minutesPresent = false;
	}

	//minutes: ASSUMES START WITH NUMBER
	if (minutesPresent == true && (temp < 1 || temp > 59))
	{
		cerr << endl << "minutes OOB" << endl;
		return false;
	}

	if (rowerString[index] != ':')
	{
		cerr << endl << "no colon between min and sec" << endl;
		return false;
	}
	index++;

	//seconds: uses numberX to account for the allowability of starting 0's
	temp = numberX(rowerString, index);
	if (temp < 0 || temp > 59)
	{
		cerr << endl << "seconds OOB" << endl;
		return false;
	}

	//strokes per minute
	temp = number(rowerString, index);
	if (temp < 1 || temp > 999)
	{
		cerr << endl << "s/m OOB" << endl;
		return false;
	}
	
	//check units
	if (rowerString.substr(index, 4) != " s/m")
	{
		cerr << endl << "no s/m units OR extra chars/no space" << endl;
		return false;
	}
	index += 4;

	//distance
	temp = number(rowerString, index);
	if (temp < 1)
	{
		cerr << endl << "distance OOB" << endl;
		return false;
	}

	//check units
	if (rowerString.substr(index, 2) != " m")
	{
		cerr << endl << "no m units OR extra chars/no space" << endl;
		return false;
	}
	index += 2;

	//heartrate
	temp = number(rowerString, index);
	if (temp < 1 || temp > 999)
	{
		cerr << endl << "heartrate OOB" << endl;
		return false;
	}

	//check remainder
	//110_
	if (index < rowerString.size())
	{
			cerr << endl << "extra chars at end" << endl;
			return false;
	}

	return true;
}

int totalDistance(string rowerString)
{
	if (isValidRowerString(rowerString))
	{
		//since "distance" is the 4th number section, there needs to be 3 spaces read before you've "arrived" at the distance section
		return retNum(rowerString, 3);
	}
	return -1;
}

int heartRate(string rowerString)
{
	if (isValidRowerString(rowerString))
	{
		//since "heartrate" is the 5th number section, there needs to be 4 spaces read before you've "arrived" at the heartrate section
		return retNum(rowerString, 4);
	}
	return -1;
}

int strokesPerMinute(string rowerString)
{
	if (isValidRowerString(rowerString))
	{
		//since "s/m" is the 3rd number section, there needs to be 2 spaces read before you've "arrived" at the s/m section
		return retNum(rowerString, 2);
	}
	return -1;
}

int elapsedMinutes(string rowerString)
{
	if (isValidRowerString(rowerString))
	{
		//since "mins" is the 1st number section, there needs to be 0 spaces read before you've "arrived" at the mins section
		return retNum(rowerString, 0);
	}
	return -1;
}

int elapsedSeconds(string rowerString)
{
	if (isValidRowerString(rowerString))
	{
		//since "seconds" is the 2nd number section, there needs to be only 1 space read before you've "arrived" at the seconds section
		return retNum(rowerString, 1);
	}
	return -1;
}

//Returns the numerical value up to the first non-numeral value and updates startingPos to the "next" index
//If there is no numeral immediately found/after white space, the program will return 0... -1 seems to never run
int number(string s, int& startingposition)
{
	int result = 0;

	// ignore leading whitespace
	while (startingposition < s.length() && isspace(s.at(startingposition)))
	{
		startingposition = startingposition + 1;
	}

	// no leading zeros
	if (startingposition < s.length())
	{
		if (s.at(startingposition) >= '1' && s.at(startingposition) <= '9')
		{
			while (startingposition < s.length() && s.at(startingposition) >= '0' && s.at(startingposition) <= '9')
			{
				int value = s.at(startingposition) - '0';

				result = (result * 10) + value;

				/// move on down the road
				startingposition = startingposition + 1;
			}
		}
	}
	else
		result = -1;
	return(result);
}

//modified number() function that allows up to two leading 0's to allow seconds like "00" and "01" etc.
int numberX(string s, int& startingposition)
{
	int result = 0;

	// ignore leading whitespace
	while (startingposition < s.length() && isspace(s.at(startingposition)))
	{
		startingposition = startingposition + 1;
	}

	// no leading zeros
	if (startingposition < s.length())
	{
		if (s.at(startingposition) >= '0' && s.at(startingposition) <= '9')
		{
			int onlyTwo = 1;
			while (startingposition < s.length() && s.at(startingposition) >= '0' && s.at(startingposition) <= '9' && onlyTwo <= 2)
			{
				int value = s.at(startingposition) - '0';

				result = (result * 10) + value;

				/// move on down the road
				startingposition = startingposition + 1;
				onlyTwo++;
			}
		}
	}
	else
		result = -1;
	return(result);
}


//prereq: based on how I use this, the old string is a VALID rowerString
//takes an old string and puts all the numbers into it with spaces between each section
//ex. the string "1:14 28 s/m 42 m 110" gets put into the form "1 14 28 42 110"
string pullNums(string old)
{
	string ret = "";

	bool passedColon = false;

	for (int i = 0; i < old.size(); i++)
	{
		if (isdigit(old[i]))
		{
			ret += old[i];
		}
		else if (old[i] == ':')
		{
			passedColon = true;
			ret += ' ';
		}
		//if you passed the colon and run into a space, that means we've proceeded to the next section and need a space
		else if (passedColon && old[i] == ' ')
		{
			passedColon = false; // don't need this triggered anymore
			ret += ' ';
		}
		else if (old[i] == 'm')
		{
			ret += ' ';
		}

		//SUM: total of 4 spaces needed: colon, between time and s/m, between s/m and m, and m and heartbeat (m cases are handled using the same case = only 3 total if's
	}

	return ret;
}

int retNum(string s, int numSpaces)
{
	string readMe = pullNums(s);

	//hardcode a case for 0 minutes
	if (numSpaces == 0 && readMe[0] == ' ')
	{
		//cerr << "{" << readMe[0] << "}";
		return 0;
	}

	int spaces = 0;
	int index = 0;
	while (spaces < numSpaces)
	{
		if (isspace(readMe[index]))
		{
			spaces++;
		}
		index++;
	}
	return number(readMe, index);
}