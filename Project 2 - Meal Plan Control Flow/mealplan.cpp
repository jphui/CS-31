#include <iostream>
using namespace std;
#include <string>

int main()
{
	int key = 0;										//See the comment above the switch
	
	string method;										//"method" handles the method of payment
	cout << "Ticket or BruinCard? ";
	getline(cin, method);
	//cout << method << endl;							//debugging snippet
	if (method == "Ticket")								//These if statements begin creating a unique ID for the final result (see switch)
		key += 1;
	else if (method == "BruinCard")
		key += 2;
	else                                                //Handles unexpected input
	{
		cout << "The kind value must either be Ticket or BruinCard." << endl;
		return (-1);
	}


	string meal;										//"meal" handles the specific meal the person is having
	cout << "Breakfast, Lunch or Dinner? ";
	getline(cin, meal);
	if (meal == "Breakfast")							//These if statements continue creating a unique ID for the final result (see switch)
		key += 3;
	else if (meal == "Lunch")
		key += 5;
	else if (meal == "Dinner")
		key += 7;
	else                                                //Handles unexpected input
	{
		cout << "The meal value must either be Breakfast, Lunch or Dinner." << endl;
		return (-2);
	}


	if (method != "Ticket")								//will only run student/staff if using a BruinCard (!Ticket)
	{
		string status;									//"status" handles the person's status as a student or staff
		cout << "Student or Staff? ";
		getline(cin, status);
		if (status == "Student")						//These if statements continue creating a unique ID for the final result (see switch)
			key += 10;
		else if (status == "Staff")
			key += 13;
		else                                            //Handles unexpected input
		{
			cout << "The type value must either be Student or Staff." << endl;
			return (-3);
		}

		
		if (status == "Student")						//will only run resident/nonResident if the person IS a student
		{
			string rez;									//"rez" handles the residency part of the cost
			cout << "Resident? ";
			getline(cin, rez);
			if (rez == "Yes")							//These if statements continue creating a unique ID for the final result (see switch)
				key += 18;
			else if (rez == "No")
				key += 21;
			else                                        //Handles unexpected input
			{
				cout << "The resident value must either be Yes or No." << endl;
				return (-4);
			}
		}
	}

	/*
	Basically I've implemented what amounts to a map of sorts:
	- each combo has a unique "key" ID number, and I've used a switch to
	decide what value should be printed out
	- as you can see by the lines which redefine "key", the way I created
	unique ID's was by incrementing "key" by unique values based on
	user's input
	- I realized early on that if the key ID's were incremented by "1"
	only, then there'd be problems where chosing a "lower value" of one
	and a "higher value" of another would have the same ID as a "higher"
	ID of one and a "lower" ID of the other... thus the spacing between
	incrementation was changed in each category to prevent this from
	happening! (not sure if it would have made a difference in this
	specific project, but good practice I guess anyway...)
	*/

	double price = -1.0;	//creates a variable to store the price, which starts at a negative value because we EXPECT price to be redefined!

	/*
	The comments beside each case are code for the meaning of each ID:
	1) First Character: T = Ticket, B = BruinCard
	2) Second Character: B = Breakfast, L = Lunch, D = Dinner
	3) Third "phrase": Stu = Student, Sta = Staff
	4) Last Character ("fourth"): Y = Yes, N = No
	*/

	switch (key)
	{
	case 4: //TB
		price = 12.50;
		break;
	case 6: //TL
		price = 14.50;
		break;
	case 8: //TD
		price = 17.00;
		break;

	case 33: //BBStuY
		price = 9.75;
		break;
	case 36: //BBStuN
		price = 10.00;
		break;
	case 18: //BBSta
		price = 11.25;
		break;

	case 35: //BLStuY
		price = 11.25;
		break;
	case 38: //BLStuN
		price = 11.75;
		break;
	case 20: //BLSta
		price = 12.75;
		break;

	case 37: //BDStuY
		price = 12.25;
		break;
	case 40: //BDStuN
		price = 12.75;
		break;
	case 22: //BDSta
		price = 14.75;
		break;

	default:
		return (-5);
	}

	cout.setf(ios::showpoint);
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << "Thank you for eating at UCLA today.  Your meal cost is $" << price << "." << endl;
	
	return (0);
}