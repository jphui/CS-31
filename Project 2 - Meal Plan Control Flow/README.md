# Project 2 - Meal Plan Control Flow

**Difficulties Encountered**

One of the main obstacles I overcame, as seen in the implementation of the switch statement, is how to efficiently designate each case a price. Intuitively, it’s sort of a dichotomous key where your inputs “filter down” into a specific price, but I didn’t think that writing a bunch of if-statements was the most efficient way to accomplish my goal, nor did I want to write a lot of if-statements. So, I thought of a way to implement a switch by creating a unique ID number for each case through a sort-of map: if statements used to check validity of inputs doubled as incrementing a “key” value for each case, and at the end the sum was assigned a price. A problem that I tried to avoid but ended having to solve was two different cases having the same ID (but different prices). When the sums were worked out, two different cases summed to “36” so I had to figure out a difference between the cases and increment the sum by one so they’d be different. In the end, I think my implementation worked out very well and solidified my understanding of switches.

**Test Cases**

Test cases that would be good to run to test my code would involve the failure cases in which the error messages such as “The meal value must be either be Breakfast, Lunch or Dinner.” print out.

    a.	Incorrect method: (BCard)
    b.	Incorrect meal type: (BruinCard, Brunch)
    c.	Incorrect status: (BruinCard, Lunch, Faculty)
    d.	Incorrect residency: (BruinCard, Lunch, Student, Nyes)
    e.	Running Ticket to see if it prompts for status and residency: (Ticket, Breakfast)  
        i.	It should NOT prompt for status and residency
    f.	Running Staff to see if it prompts for residency: (BruinCard, Lunch, Staff) 
        i.	It should NOT prompt for residency
    g.	Correct everything to make sure the formatting of the ideal case prints correctly and has the right prices.
        i.	12 cases total as seen in the Meal Plan Costs chart on the assignment page
        ii.	Make sure 2 decimal places shows up
    h.	Inputting an empty string on purpose to make sure it’s handled by the error messages
Of all these marker cases, my program did not run into any issues! Yay!