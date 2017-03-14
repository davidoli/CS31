#ifndef Candidate_H
#define Candidate_H

#include <iostream>
#include <string>

using namespace std;


class Candidate {
	string name;
	string slogan;
	int delegates;

public:
	Candidate();                        //default constructor
	Candidate(string, string, int);     //overload constructor
	~Candidate();                       //destructor
	
										//getters and setters
	string getName();
	void setName(string name);
	string getSlogan();
	void setSlogan(string slogan);
	int getDelegates();
	void setDelegates(int delegates);
};
#endif