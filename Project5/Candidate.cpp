#include "Candidate.h";
#include <iostream>
#include <string>

Candidate::Candidate() {
	name = "";
	slogan = "";
	delegates = 0;
}
Candidate::Candidate(string newName, string newSlogan, int newDelegates) {
	name = newName;
	slogan = newSlogan;
	delegates = newDelegates;

	try {                                 // exception made for negative delegates
		if (delegates < 0)
			throw 1;
	}
	catch (int x) {
		cout << "Number of delegates cannot be negative.  Will change delegates to 0." << endl;
		delegates = 0;
	}
}
Candidate::~Candidate(){}

string Candidate::getName() {
	return name;
}
void Candidate::setName(string initName) {
	name = initName;
}
string Candidate::getSlogan() {
	return slogan;
}
void Candidate::setSlogan(string initSlogan) {
	slogan = initSlogan;
}
int Candidate::getDelegates() {
	return delegates;
}
void Candidate::setDelegates(int initDelegates) {
		delegates = initDelegates;

		try {
			if (delegates < 0)
				throw 1;                                //exception for negative values
		}
		catch (int x) {
			cout << "Number of delegates cannot be negative.  Will change delegates to 0." << endl;
			delegates = 0;
		}
	}
