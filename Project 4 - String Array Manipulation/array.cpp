#include <iostream>

#include <string>
#include <cassert>
#include <cctype>

using namespace std;

bool hasDuplicates(const string array[], int size);
int  countAllDigits(const string array[], int size);
bool isInDecreasingOrder(const string array[], int size);
int  shiftRight(string array[], int size, int amount, string placeholder);
int  find(const string array[], int size, string match);
int  replaceAllCharacters(string array[], int size, char findLetter, char replaceLetter);

void printMe(const string array[], int size);

int main() {
	string a[6] = { "alpha", "beta", "gamma", "gamma", "beta", "delta" };

	assert(hasDuplicates(a, 3) == false);
	assert(hasDuplicates(a, 6) == true);

	string folks[8] = {
		"samwell", "jon", "margaery", "daenerys",
		"tyrion", "sansa", "howard123", "jon"
	};

	assert(find(folks, 5, "foo") == -1);
	assert(find(folks, -500, "foo") == -1);
	assert(find(folks, 8, "jon") == 1);

	assert(hasDuplicates(folks, 5) == false);
	assert(hasDuplicates(folks, -1) == false);
	assert(hasDuplicates(folks, 8) == true);

	assert(countAllDigits(folks, 8) == 3);
	assert(countAllDigits(folks, -108) == -1);

	string people[5] = { "samwell", "jon", "margaery", "daenerys", "tyrion" };

	assert(isInDecreasingOrder(people, 5) == false);
	assert(isInDecreasingOrder(people, 0) == true);
	assert(isInDecreasingOrder(people, 1) == true);

	string people2[5] = { "samwell", "jon", "margaery", "daenerys", "tyrion" };
	string people3[5] = { "samwell", "jon", "margaery", "daenerys", "tyrion" };

	assert(shiftRight(people, 5, 3, "foo") == 3);
	cerr << "The array should be: { foo, foo, foo, samwell, jon }" << endl;
	printMe(people, 5);
	cerr << endl;
	assert(shiftRight(people2, -5, 3, "foo") == -1);
	cerr << "The array should be: { samwell, jon, margaery, daenerys, tyrion }" << endl;
	printMe(people2, 5);
	cerr << endl;
	assert(shiftRight(people3, 5, 25, "foo") == 5);
	cerr << "The array should be: { foo, foo, foo, foo, foo }" << endl;
	printMe(people3, 5);
	cerr << endl;

	string people4[5] = { "samwell", "jon", "margaery", "daenerys", "tyrion" };
	string people5[5] = { "samwell", "jon", "margaery", "daenerys", "tyrion" };
	string people6[5] = { "samwell", "jon", "margaery", "daenerys", "tyrion" };

	assert(replaceAllCharacters(people4, 5, 'z', 'a') == 0);
	cerr << "The array should be: { samwell, jon, margaery, daenerys, tyrion }" << endl;
	printMe(people4, 5);
	cerr << endl;
	assert(replaceAllCharacters(people5, -5, 'z', 'a') == -1);
	cerr << "The array should be: { samwell, jon, margaery, daenerys, tyrion }" << endl;
	printMe(people5, 5);
	cerr << endl;
	assert(replaceAllCharacters(people6, 5, 'a', '_') == 4);
	cerr << "The array should be: { s_mwell, jon, m_rg_ery, d_enerys, tyrion }" << endl;
	printMe(people6, 5);
	cerr << endl;

	cerr << "All tests succeeded" << endl;
	return(0);
}

//utilizes find() by searching for everything up to but excluding the index: if find() finds the same element "before" i, then there has to be a dupe
bool hasDuplicates(const string array[], int size) {
	for (int i = 0; i < size; i++) {
		if (find(array, i, array[i]) != -1)
			return true;
	}
	return false;
}

//nested for-loops loops through the array, then through the strings themselves, using isdigit() to check for numbers
int  countAllDigits(const string array[], int size) {
	if (size <= 0)
		return -1;
	int ret = 0;
	for (int i = 0; i < size; i++) {
		for (size_t j = 0; j < array[i].length(); j++) {
			if (isdigit(array[i].at(j)))
				ret++;
		}
	}
	return ret;
}

//Specifically i am comparing i to i+1, so note how I don't go all the way up to size, but size-1
bool isInDecreasingOrder(const string array[], int size) {
	if (size < 0)
		return false;
	for (int i = 0; i < size - 1; i++) {
		if (array[i] >= array[i + 1])
			return false;
	}
	return true;
}

int  shiftRight(string array[], int size, int amount, string placeholder) {
	if (size < 0)
		return -1;

	//if amount < size, then this means there will be some of the OG array left, thus there needs to be actual shifting!
	if (amount < size) {
		string temp;
		for (int i = 0; (i + amount) < size; i++) {
			temp = array[i + amount];
			array[i + amount] = array[i];
		}
	}

	//in both cases, there needs to be filling involved, so here is that:
	int i = 0;
	for (i; (i < size) && (i < amount); i++) {
		array[i] = placeholder;
	}

	return i;
}

//simple for-loop that loops through and return the index i of the index where the match was found
int  find(const string array[], int size, string match) {
	for (int i = 0; i < size; i++) {
		if (array[i] == match)
			return i;
	}
	return -1;
}

int  replaceAllCharacters(string array[], int size, char findLetter, char replaceLetter) {
	if (size <= 0)
		return -1;
	int ret = 0;
	for (int i = 0; i < size; i++) {
		for (size_t j = 0; j < array[i].length(); j++) {
			if (array[i].at(j) == findLetter) {
				array[i][j] = replaceLetter;
				ret++;
			}
		}
	}
	return ret;
}

//helper program to print out my array's
void printMe(const string array[], int size) {
	for (int i = 0; i < size; i++) {
		cerr << array[i] << ", ";
	}
}