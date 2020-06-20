# Project 5 - Object-Oriented Box Office

**Difficulties Encountered**

My most notable obstacle was finding test cases to test my code. I have background in Java so object-oriented programming is my turf and I got the concepts pretty quick… it was mainly an issue with C++’s shenanigans like splitting a class into a .cpp and a .h, putting ClassName:: before every single thing in the .cpp file, and using #include. I also spent a considerable amount of effort trying to tie the four BoxOffice methods together, since I realized there was a hierarchy of sorts where you can use the base BuyTicket IN the BuyRoyceHallTicket, then BRHT in each of the specialized student and staff versions. Very quickly, I realized, too that using a calculate() method to find the base, before-student/staff discounts was a good thing since abstraction cut down on the overall amount of code I needed.

**Test Cases**

This code set should be used right after you write the Ticket class to ensure the constructor initializes everything correctly, and subsequently, that the public methods all work and get/set everything right.

    Ticket a = Ticket("A", 4, "boom", "royce", 1.1, Ticket::KIND::ATHLETICGAME, "yes");
        assert(a.getRow() == "A");
        assert(a.getSeat() == 4);
        assert(a.getEvent() == "boom");
        assert(a.getVenue() == "royce");
        assert(a.getPrice() == 1.1);
        assert(a.getKind() == Ticket::KIND::ATHLETICGAME);
        assert(a.getDayTime() == "yes");
        a.setPrice(19.0);
        assert(a.getPrice() == 19.0);

This code here is just to make sure that the helper code is working and that you #included the header file. Since it was given, there should be zero problems here at all.

    Project5Helper helper;
        assert(helper.endsWithPM("sdfasddf PM"));
        assert(!helper.endsWithPM("asdasdfs AM"));
        assert(helper.startsWithOrchestra("Orchestra 12445"));
        assert(!helper.startsWithOrchestra("122334 Orchestra"));
	
This code again tests the Ticket constructor but was Stahl-generated to be more in line with actual, real-life input (unlike my first set of code which was user-generated).

    Ticket t("Pavillion Row 13", 45, "Dodgers vs. Brewers", "Dodger Stadium", 150.00, Ticket::KIND::ATHLETICGAME, "August 1, 7:30PM");
        assert(std::to_string(t.getPrice()) == "150.000000");
        assert(t.getKind() == Ticket::KIND::ATHLETICGAME);
        assert(t.getRow() == "Pavillion Row 13");
        assert(t.getSeat() == 45);
    BoxOffice b;   //creates a BoxOffice object to actually test its code for the next 4 sets of test code.

This was an idea by me to specifically test the buyTicket method in the BoxOffice class since it seems to have been originally intended as a helper function. Thus, if the RoyceHall ones run, it should be fine, but having a test set for it alone can help with debugging it specifically.

    t = b.buyTicket("Pavillion Row 13", 45, "Dodgers vs. Brewers", "Dodger Stadium", Ticket::KIND::ATHLETICGAME, "August 1, 7:30PM");
        t.setPrice(150);
        assert(std::to_string(t.getPrice()) == "150.000000");
        assert(t.getKind() == Ticket::KIND::ATHLETICGAME);
        assert(t.getRow() == "Pavillion Row 13");
        assert(t.getSeat() == 45);

Student situation to test the discount.

    t = b.buyRoyceHallStudentTicket("Orchestra Row U", 20, "Episode VII: The Force Awakens", Ticket::KIND::MOVIE, "September 1, 7:30PM");
        assert(std::to_string(t.getPrice()) == "20.000000");
        assert(t.getKind() == Ticket::KIND::MOVIE);
        assert(t.getRow() == "Orchestra Row U");
        assert(t.getSeat() == 20);
        t.setPrice(5);
        assert(t.getPrice() == 5.0000000000000);

Staff situation to test the discount.

    t = b.buyRoyceHallStaffTicket("Balcony Row J", 120, "An Evening With David Sedaris", Ticket::KIND::OTHER, "October 1, 7:30PM");
        assert(std::to_string(t.getPrice()) == "35.000000");
        assert(t.getKind() == Ticket::KIND::OTHER);
        assert(t.getRow() == "Balcony Row J");
        assert(t.getSeat() == 120);

Running this code BEFORE the Student/Staff sets can make sure the calculate() helper method I wrote works, a good idea to debug that before using this method as a part of the case-specific student-staff methods!

    t = b.buyRoyceHallTicket("Orchestra Row A", 12, "Barry Manilow Live In Concert", Ticket::KIND::CONCERT, "November 1, 7:30PM");
        assert(std::to_string(t.getPrice()) == "130.000000");
        assert(t.getKind() == Ticket::KIND::CONCERT);
        assert(t.getRow() == "Orchestra Row A");
        assert(t.getSeat() == 12);
