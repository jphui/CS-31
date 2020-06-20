#include "Ticket.h"
#include "BoxOffice.h"
#include "Project5Helper.h"

#include <string>
#include <cstdlib>
#include <iostream>

#include <cassert>

using namespace std;

int main()
{
	Ticket a = Ticket("A", 4, "boom", "royce", 1.1, Ticket::KIND::ATHLETICGAME, "yes");
	assert(a.getRow() == "A");
	assert(a.getSeat() == 4);
	assert(a.getEvent() == "boom");
	assert(a.getVenue() == "royce");
	assert(a.getPrice() == 1.1);
	assert(a.getKind() == Ticket::KIND::ATHLETICGAME);
	assert(a.getDayTime() == "yes");
	a.setPrice(19);
	assert(a.getPrice() == 19.0);

	Project5Helper helper;
	assert(helper.endsWithPM("sdfasddf PM"));
	assert(!helper.endsWithPM("asdasdfs AM"));
	assert(helper.startsWithOrchestra("Orchestra 12445"));
	assert(!helper.startsWithOrchestra("122334 Orchestra"));

	Ticket t("Pavillion Row 13", 45, "Dodgers vs. Brewers", "Dodger Stadium", 150.00, Ticket::KIND::ATHLETICGAME, "August 1, 7:30PM");
	BoxOffice b;
	assert(std::to_string(t.getPrice()) == "150.000000");
	assert(t.getKind() == Ticket::KIND::ATHLETICGAME);
	assert(t.getRow() == "Pavillion Row 13");
	assert(t.getSeat() == 45);

	t = b.buyTicket("Pavillion Row 13", 45, "Dodgers vs. Brewers", "Dodger Stadium", Ticket::KIND::ATHLETICGAME, "August 1, 7:30PM");
	t.setPrice(150);
	assert(std::to_string(t.getPrice()) == "150.000000");
	assert(t.getKind() == Ticket::KIND::ATHLETICGAME);
	assert(t.getRow() == "Pavillion Row 13");
	assert(t.getSeat() == 45);


	t = b.buyRoyceHallStudentTicket("Orchestra Row U", 20, "Episode VII: The Force Awakens", Ticket::KIND::MOVIE, "September 1, 7:30PM");
	assert(std::to_string(t.getPrice()) == "20.000000");
	assert(t.getKind() == Ticket::KIND::MOVIE);
	assert(t.getRow() == "Orchestra Row U");
	assert(t.getSeat() == 20);

	t.setPrice(5);
	assert(t.getPrice() == 5.0000000000000);

	t = b.buyRoyceHallStaffTicket("Balcony Row J", 120, "An Evening With David Sedaris", Ticket::KIND::OTHER, "October 1, 7:30PM");
	assert(std::to_string(t.getPrice()) == "35.000000");
	assert(t.getKind() == Ticket::KIND::OTHER);
	assert(t.getRow() == "Balcony Row J");
	assert(t.getSeat() == 120);

	t = b.buyRoyceHallTicket("Orchestra Row A", 12, "Barry Manilow Live In Concert", Ticket::KIND::CONCERT, "November 1, 7:30PM");
	assert(std::to_string(t.getPrice()) == "130.000000");
	assert(t.getKind() == Ticket::KIND::CONCERT);
	assert(t.getRow() == "Orchestra Row A");
	assert(t.getSeat() == 12);

	cerr << "Pass!" << endl;

	return 0;
}