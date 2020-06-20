#include "BoxOffice.h"

#include <string>
#include <cstdlib>

double calculate(string row, Ticket::KIND kind, string daytime);

BoxOffice::BoxOffice()
{

}

Ticket BoxOffice::buyTicket(string row, int seat, string event, string venue, Ticket::KIND kind, string daytime)
{
	Ticket ret = Ticket(row, seat, event, venue, 0.0, kind, daytime);
	return ret;
}
Ticket BoxOffice::buyRoyceHallStudentTicket(string row, int seat, string event, Ticket::KIND kind, string daytime)
{
	Ticket ret = buyRoyceHallTicket(row, seat, event, kind, daytime);
	double newPrice = ret.getPrice();
	if (newPrice >= 40.0)
		newPrice -= 30.0;
	else
		newPrice *= .8;
	ret.setPrice(newPrice);
	return ret;
}
Ticket BoxOffice::buyRoyceHallStaffTicket(string row, int seat, string event, Ticket::KIND kind, string daytime)
{
	Ticket ret = buyRoyceHallTicket(row, seat, event, kind, daytime);
	double newPrice = ret.getPrice();
	if (newPrice >= 40.0)
		newPrice -= 20.0;
	else
		newPrice *= .9;
	ret.setPrice(newPrice);
	return ret;
}
Ticket BoxOffice::buyRoyceHallTicket(string row, int seat, string event, Ticket::KIND kind, string daytime)
{
	Ticket ret = buyTicket(row, seat, event, "Royce Hall", kind, daytime);
	double og = calculate(row, kind, daytime);
	ret.setPrice(og);
	return ret;
}
//discounts are not handled here because it's specific to the caller!!!
double calculate(string row, Ticket::KIND kind, string daytime)
{
	Project5Helper helpMe = Project5Helper();
	bool PM = helpMe.endsWithPM(daytime);
	bool orch = helpMe.startsWithOrchestra(row);

	double ret = 0.0;

	switch (kind)
	{
	case 0: //ATHLETICGAME = 75 base
		ret = 75.0;
		if (orch)
			ret = 150.0;
		break;
	case 1: //CONCERT = 50, 65 if PM
		ret = 50.0;
		if (PM)
			ret = 65.0;
		if (orch)
			ret *= 2;
		break;
	case 2: //MOVIE = 12.5
		ret = 12.5;
		if (orch)
			ret *= 2;
		break;
	case 3: //OTHER = 40, 55 if PM
		ret = 40.0;
		if (PM)
			ret = 55.0;
		if (orch)
			ret *= 2;
		break;
	default:
		ret = 0.0;
	}
	
	return ret;
}