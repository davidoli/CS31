#include <iostream>
#include <string>
#include "Candidate.h"
#include <cassert>

using namespace std;

Candidate selectNominee(Candidate c1, Candidate c2 = Candidate(), Candidate c3 = Candidate(), Candidate c4 = Candidate(), Candidate c5 = Candidate()) {
	Candidate delegates[] = { c1, c2, c3, c4, c5 };                                      //array of candidates
	int array[] = { c1.getDelegates(), c2.getDelegates(), c3.getDelegates(), c4.getDelegates(), c5.getDelegates() };   //array of their delegate count
	int largest = -1;
	Candidate nominee;
	for (int k = 0; k < 5; k++) {
		if (array[k] > largest) {
			largest = array[k];               //set largest count as new largest in array
			nominee = delegates[k];             // if equal delegate count, return Candidate that had the number first in array.
		}
	}
	return nominee;

}
int main() {

	string name;
	string slogan;
	int delegates;

	cout << "enter a name: " << endl;
	getline(cin, name);
	cout << "enter a slogan: " << endl;
	getline(cin, slogan);
	cout << "enter number of delegates: " << endl;
	cin >> delegates;


	Candidate c1(name, slogan, delegates);
	cout << "Candidate Name: " << c1.getName() << endl;
	cout << "Candidate Slogan: " << c1.getSlogan() << endl;
	cout << "Candidate has " << c1.getDelegates() << " of delegates" << endl;

	Candidate c2("John Coltrane", "I play the sax.", -12);
	cout << "Candidate Name: " << c2.getName() << endl;
	cout << "Candidate Slogan: " << c2.getSlogan() << endl;
	cout << "Candidate has " << c2.getDelegates() << " of delegates" << endl;
	Candidate c3("Miles Davis", "I wrote the greatest jazz record of all time.", 50);
	cout << "Candidate Name: " << c3.getName() << endl;
	cout << "Candidate Slogan: " << c3.getSlogan() << endl;
	cout << "Candidate has " << c3.getDelegates() << " of delegates" << endl;
	Candidate c4("Bill Evans", "I made that one Snow White tune famous.", 100);
	cout << "Candidate Name: " << c4.getName() << endl;
	cout << "Candidate Slogan: " << c4.getSlogan() << endl;
	cout << "Candidate has " << c4.getDelegates() << " of delegates" << endl;
	
	cout << "The Candidate with the most delegates is " << selectNominee(c1, c2, c3, c4).getName() << "." << endl;

	Candidate donald("Donald", "Make America Great Again", 0);
	assert(donald.getName() == "Donald");
	assert(donald.getSlogan() == "Make America Great Again");
	assert(donald.getDelegates() == 0);
	Candidate c = selectNominee(donald);
	assert(c.getName() == "Donald");
	assert(c.getSlogan() == "Make America Great Again");
	assert(c.getDelegates() == 0);

	cout << "all tests passed!" << endl;

	return 0;
}