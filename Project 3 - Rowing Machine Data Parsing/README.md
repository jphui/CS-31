# Project 3 - Rowing Machine Data Parsing

**Difficulties Encountered**

I was super slow to start the project since I didn&#39;t really know how to &quot;read stuff into a string&quot;, but after a couple of hours of just thinking and no work I decided to brute force the project, which in a way is the most efficient way to accomplish the different tasks. I was trying to think of a general formula that would be able to read things in without having too many if-cases, but after a while I realized that it would be hard to find a catch-all approach and after that everything became easy as I found some common patterns (checking the units, redefining a temp variable to store a read-in number).

**General Approach**

For starters, main() has the for-loop test code that was provided on CCLE. Although I think that for documentation purposes using assert would have been better, I liked being able to change the input line on the fly as I saw fit rather than having it hard-coded into my program. I do have remnants of the assert lines in there for reference, but I relied only on the infinite for-loop to do my debugging.

As for the actual code, I would say that my isValidRowerString() function is very linear in approach, reflecting my inability to find a formula that I could use to read each of the sets of numbers in an iterative way. Instead, I used the hints provided in the FAQ to make &quot;simplifying assumptions&quot; such as &quot;the input is assumed to start with a number&quot; and working from there.

Starting from that assumption, I read in the minutes with the number function, and if it was determined to be out of range, returned false.

I then checked for the colon, proceeding to read in the seconds with the same manner of checking, which was having a temp int value that stored what number() returned, allowing the index variable to change as the number() function kept track of where in the rowerString input the program was at any given moment in time.

After checking each &quot;set&quot; of data (minutes, seconds, row rate, distance, heartrate), I went back and coded a &quot;catch&quot; for no-minute cases, which used a Boolean to skip or not skip the if-statement that checked for minutes.

At this point, my code was basically complete, but I still had an issue with leading 0&#39;s in the seconds place, an issue hard-coded into the given number() function. As to not mess up my existing code, I duplicated number() into numberX(), which did the same thing but allowed up to two 0&#39;s to account for second values 00  09.

In terms of the data-return functions, I was a bit more efficient with the solutions here. I created two helper functions which made the actual functions very simple, as the main factor that differentiated them was where in the string you needed to parse the number data.

First, I made a function that got rid of all non-numbers and put a space between each field.

Then I made a function that skipped a passed-in number of spaces (which was based on the specific data required – for example, &quot;seconds&quot; was the second data field, thus there would be 1 space to skip before arriving at the seconds value) to see where in the new string to look, calling number() to return the number after that space.

At this point, the helper functions did all the work, and I just had to call them differently based on which data I wanted.

**Test Cases**
  1. These are all the valid cases mentioned in the Spec, so at the very least these should succeed:

    :14 28 s/m 42 m 110
        :14      28 s/m   42 m     110
    1:14 28 s/m 42 m 110
    59:14 28 s/m 42 m 110
    59:59 28 s/m 42 m 110
    59:59 999 s/m 42 m 110
    59:59 999 s/m 42 m 999
  2. These are all the invalid cases mentioned in the Spec, so at the very least these should fail:

    asdf:14 28 s/m 42 m 110
    :14 28 s/m 42 m 110 asdf
    :14 28      s/m 42 m 110
    0:14 28 s/m 42 m 110
    0000:14 00028 s/m 00042 m 000110
    :-14 -28 s/m -42 m -110
    555:14 28 s/m 42 m 110
    :555 28 s/m 42 m 110
    :14 99123 s/m 42 m 110
    :14 0 s/m 42 m 110
    :14 28 s/m 42 m 99123
    :14 28 s/m 42 m 0
  3. A few other cases that should FAIL:

    9:0a 56 s/m 42 m 110
    9:00 5a6 s/m 42 m 110
    9:00 56 s/m 4a2 m 110
    9:00 56 s/m 42 m 1a0
    9:00 56as/m 42 m 100
  4. Cases that should WORK: (edgy)

    9:00 56 s/m 42 m 100
    9:05 56 s/m 42 m 100