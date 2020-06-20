# Project 4 - String Array Manipulation

**Difficulties Encountered**

I actually didn’t run into many obstacles, but something I definitely could have run into was if I hadn’t read through the methods I needed to code first: the find() function made the hasDuplicates() function so much easier to write, since I was able to use find() itself. The alternative method I was about to write was going to be creating another array and copying elements into them, and if a for loop detected that at [i], there already existed that word in the array, then there would be a dupe. However, using find() and my realization that the mini-array already existed inside the current one from 0 --> i-1, I was able to make this so much more efficient.

I did run into some coder’s block when I was trying to figure out how to write shiftRight() in an efficient way. I knew what it was supposed to do, but the fact that there were 2 cases where you returned size vs amount confused me. However, I realized that you can put two conditions inside a for-loop so that the index variable always maxes out at the right value.

**Test Cases**

Test Data Cases: there were a lot of test cases given in the project spec, so here is a brief compilation of them.

a. string a[6] = { "alpha", "beta", "gamma", "gamma", "beta", "delta" };
- hasDuplicates(a, 3) should return false
- hasDuplicates(a, 6) should return true
- These tests run to make sure that both hasDupes and find work, since hasDupes uses find. Specifically, since our 6-size contains two “gammas” but our 3 doesn’t, the success should show that our code correctly uses the size parameter.

b. string folks[8] = { "samwell", "jon", "margaery", "daenerys", "tyrion", "sansa", "howard123", "jon" };
- find(folks, 5, “foo”) should return -1
    - This is a “base case” test to make sure it runs ideally when there are no matches found
- find(folks, -500, “foo”) should return -1
    - This specifically tests the -size case!
- find(folks, 8, “jon”) should return 1
    - This is a “base case” test to make sure it runs ideally when there IS a match found
- hasDuplicates(folks, 5) should return false
    - When you only consider up to index 4, there are no duplicates, so the code shouldn’t say that there are
- hasDuplicates(folks, -1) should return false
    - This specifically tests the -size case!
- hasDuplicates(folks, 8) should return true
    - When considering up to index 7, there is a duplicate present, so the code should reflect as such.
- countAllDigits(folks, 8) should return 3
    - in “howard123” there are 3 digits
- countAllDigits(folks, -108) should return -1
    - This specifically tests the -size case!

c. string people[5] = { "samwell", "jon", "margaery", "daenerys", "tyrion" };
- isInDecreasingOrder(people, 5) should return false
- isInDecreasingOrder(people, 0) should return true
- isInDecreasingOrder(people, 1) should return true
    - These last two cases are to make sure specifically that size = 0 and size = 1 return true as stated in the spec

These last two sections should make use of cerr to output the modified arrays to make sure they were changed as stated in the spec! As such, writing a helper function to print out an array is a good idea!

d.	string people2[5] = { "samwell", "jon", "margaery", "daenerys", "tyrion" };

e.	string people3[5] = { "samwell", "jon", "margaery", "daenerys", "tyrion" };
- shiftRight(people, 5, 3, “foo”) should return 3
    - Since the array was shifter right 3 times, “3” should be returned. 
- shiftRight(people2, -5, 3, “foo”) should return -1
    - This specifically tests the -size case!
- shiftRight(people3, 5, 25, “foo”) should return 5
    - Although the amount was 25, the code should be able to distinguish between actually shifting the array and the number it was passed.

f.	string people4[5] = { "samwell", "jon", "margaery", "daenerys", "tyrion" };

g.	string people5[5] = { "samwell", "jon", "margaery", "daenerys", "tyrion" };

h.	string people6[5] = { "samwell", "jon", "margaery", "daenerys", "tyrion" };
- replaceAllCharacters(people4, 5, ‘z’, ‘a’) should return 0
    - There are no ‘z’s in the entire array of strings, thus although the size isn’t 0, there should be no change to the array and an output of 0
- replaceAllCharacters(people5, -5, ‘z’, ‘a’) should return -1
    - This specifically tests the -size case!
- replaceAllCharacters(people6, 5, ‘a’, ‘_’) should return 4
    - Since there are ‘a’s present in the strings, they should be replaced with underscores, and since there are 4, there should be 4 underscores in the modified array and a return value of 4.
