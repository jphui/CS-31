#ifndef BOXOFFICE_H
#define BOXOFFICE_H

#include <cstdlib>
#include <string>
using namespace std;

#include "Ticket.h"
#include "Project5Helper.h"

class BoxOffice
{
public:
	BoxOffice();

	Ticket buyTicket(string row, int seat, string event, string venue, Ticket::KIND kind, string daytime);
	Ticket buyRoyceHallStudentTicket(string row, int seat, string event, Ticket::KIND kind, string daytime);
	Ticket buyRoyceHallStaffTicket(string row, int seat, string event, Ticket::KIND kind, string daytime);
	Ticket buyRoyceHallTicket(string row, int seat, string event, Ticket::KIND kind, string daytime);

private:

};

#endif
