#include <cassert>
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool isWellFormedOrderString(string order);								 //signature for functions
int intnumber(string s, int startingposition);
string lowercase(string order);
double calculateOrderCost(string order);


bool isWellFormedOrderString(string order) {
	int cookies(0), brownies(0), icecream(0),              //defining variables for diddy riese products
	sandwich(0), sundae(0);

	bool wellformed = true;												 //default every order string will be well-formed except for following exceptions

	if (order == "") {													// empty strings aren't well-formed orders
		wellformed = false;
		return wellformed;
	}
	if (order.size() == 1){                                             //strings that are only 1 character long are all invalid.
		wellformed = false;
		return wellformed;
	}
	if (order[0] == '0') {                                                //0 is never first in string
		wellformed = false;
		return wellformed;
	}
	for (int k = 0; k != order.size(); k++) {	                        //goes through all string letters
		if (isalpha(order[k])) {								      //look for letters
			char c = lowercase(order)[k];

			if (c != 'c' && c != 'b' && c != 'i' && c != 's' && c != 'd'){    // find any invalid character (not C, B, I, S, D)
				wellformed = false;
				return wellformed;
			}
			if (isalpha(order[k + 1])){									 // there's always integers in between each character
				wellformed = false;
				return wellformed;
			}
			if (order[k + 1] == '0') {                                    //0 should never follow a letter in a string
				wellformed = false;
				return wellformed;
			}
		}
		else if (isdigit(order[k])) {																// looks for digits
			if (intnumber(order, k) > 36 || intnumber(order, k) < 0 || intnumber(order, k) == 0) {	// invalid if order amount > 36 or < 0.
				wellformed = false;
				return wellformed;
			}
			if (isdigit(order[k + 1])) {								// if digit is 10th place
				if (lowercase(order)[k + 2] == 'c')
					cookies = cookies + intnumber(order, k);
				else if (lowercase(order)[k + 2] == 'b')
					brownies = brownies + intnumber(order, k);
				else if (lowercase(order)[k + 2] == 'i')
					icecream = icecream + intnumber(order, k);
				else if (lowercase(order)[k + 2] == 's')
					sandwich = sandwich + intnumber(order, k);
				else if (lowercase(order)[k + 2] == 'd')
					sundae = sundae + intnumber(order, k);
				else {
					wellformed = false;
					return wellformed;
				}
			}
			else if (k == 0 && isalpha(order[k + 1])) {                 //first digit is ones place
				if (lowercase(order)[k + 1] == 'c')
					cookies = cookies + intnumber(order, k);
				else if (lowercase(order)[k + 1] == 'b')
					brownies = brownies + intnumber(order, k);
				else if (lowercase(order)[k + 1] == 'i')
					icecream = icecream + intnumber(order, k);
				else if (lowercase(order)[k + 1] == 's')
					sandwich = sandwich + intnumber(order, k);
				else if (lowercase(order)[k + 1] == 'd')
					sundae = sundae + intnumber(order, k);
				else {
					wellformed = false;
					return wellformed;
				}
			}
			else if (isalpha(order[k - 1]) && isalpha(order[k + 1])) {       // if digit is ones place
				if (lowercase(order)[k + 1] == 'c')
					cookies = cookies + intnumber(order, k);
				else if (lowercase(order)[k + 1] == 'b')
					brownies = brownies + intnumber(order, k);
				else if (lowercase(order)[k + 1] == 'i')
					icecream = icecream + intnumber(order, k);
				else if (lowercase(order)[k + 1] == 's')
					sandwich = sandwich + intnumber(order, k);
				else if (lowercase(order)[k + 1] == 'd')
					sundae = sundae + intnumber(order, k);
				else {
					wellformed = false;
					return wellformed;
				}
			}
		}
		else if (!isalpha(order[k]) && !isdigit(order[k])) {   //if part of string is not a number or a letter, not a good string
			wellformed = false;
			return wellformed;
		}                      
	}
	if (cookies > 36 || brownies > 36 || icecream > 36 || sandwich > 36 || sundae > 36) { //prevent from overordering
		wellformed = false;
		return wellformed;
	}
	return wellformed;
}
// _________________________________________________________________________________
int intnumber(string order, int startingposition){   // CONVERTS STRING INTO INT

	int result = 0;
	int length = order.length();
	if (length > startingposition && order[startingposition] >= '0' && order[startingposition] <= '9')
	{
		while (order[startingposition] >= '0' && order[startingposition] <= '9')
		{
			int value = order[startingposition] - '0'; // '5' -> 53-48 --> 5
			result = (result * 10) + value;
			startingposition = startingposition + 1;
		}
	}
	return(result);
}
//__________________________________________________________________________________

string lowercase(string order) {
	string lowercaseorder = "";

	for (int k = 0; k != order.size(); k++) {
		if (islower(order[k]))         
			lowercaseorder += order[k];            //adds lowercase letters to new string
		if (isupper(order[k]))
			lowercaseorder += tolower(order[k]);   //adds uppercase letters turned lowercase to new string
		if (isdigit(order[k]))
			lowercaseorder += order[k];            //adds digits to lowercase string
	}
	return lowercaseorder;
}
// ________________________________________________

double calculateOrderCost(string order) {
	
	double cost = 0.00;
	int cookies(0); int brownies(0); int icecream(0);              //defining variables for diddy riese products
	int sandwich(0); int sundae(0);
	
	if (isWellFormedOrderString(order)) {                                  // when order put into function is wellformed, determine how many of each treat & calculate cost
		for (int k = 0; k != order.size(); k++) {
			if (isdigit(order[k + 1])) {								// if digit is 10th place
				if (lowercase(order)[k + 2] == 'c')
					cookies = cookies + intnumber(order, k);
				else if (lowercase(order)[k + 2] == 'b')
					brownies = brownies + intnumber(order, k);
				else if (lowercase(order)[k + 2] == 'i')
					icecream = icecream + intnumber(order, k);
				else if (lowercase(order)[k + 2] == 's')
					sandwich = sandwich + intnumber(order, k);
				else if (lowercase(order)[k + 2] == 'd')
					sundae = sundae + intnumber(order, k);
			}
			else if (k == 0 && isalpha(order[k + 1])) {                 //first digit is ones place
				if (lowercase(order)[k + 1] == 'c')
					cookies = cookies + intnumber(order, k);
				else if (lowercase(order)[k + 1] == 'b')
					brownies = brownies + intnumber(order, k);
				else if (lowercase(order)[k + 1] == 'i')
					icecream = icecream + intnumber(order, k);
				else if (lowercase(order)[k + 1] == 's')
					sandwich = sandwich + intnumber(order, k);
				else if (lowercase(order)[k + 1] == 'd')
					sundae = sundae + intnumber(order, k);
			}
			else if (isalpha(order[k - 1]) && isalpha(order[k + 1])) {       // if digit is ones place
				if (lowercase(order)[k + 1] == 'c')
					cookies = cookies + intnumber(order, k);
				else if (lowercase(order)[k + 1] == 'b')
					brownies = brownies + intnumber(order, k);
				else if (lowercase(order)[k + 1] == 'i')
					icecream = icecream + intnumber(order, k);
				else if (lowercase(order)[k + 1] == 's')
					sandwich = sandwich + intnumber(order, k);
				else if (lowercase(order)[k + 1] == 'd')
					sundae = sundae + intnumber(order, k);

			}
		}

		while (cookies != 0) {                               //calculating cookie costs
			if (cookies >= 12) {
				cost = cost + (cookies / 12)*4.50;            //4.50 for a dozen cookies
				cookies = cookies % 12;
			}
			else if (cookies >= 6 && cookies < 12) {
				cost = cost + (cookies / 6)*2.50;            //2.50 for six cookies
				cookies = cookies % 6;
			}
			else if (cookies >= 3) {
				cost = cost + (cookies / 3)*1.25;           //1.25 for 3 cookies
				cookies = cookies % 3;
			}
			else if (cookies < 3) {
				cost = cost + cookies*.50;                   //.50 for each cookie
				cookies = cookies - cookies;
			}
		}
		while (brownies != 0) {                             //calculating brownie costs
			if (brownies >= 12) {
				cost = cost + (brownies / 12)*7.50;          // 7.50 for a dozen brownies
				brownies = brownies % 12;
			}
			else if (brownies >= 6 && brownies < 12) {       //3.75 for 6 brownies
				cost = cost + (brownies / 6)*3.75;
				brownies = brownies % 6;
			}
			else if (brownies >= 2 && brownies < 6) {
				cost = cost + (brownies / 2)*1.25;                 //1.25 for 2 brownies
				brownies = brownies % 2;
			}
			else if (brownies < 2) {
				cost = cost + brownies*.75;							  //.75 for one brownie
				brownies = brownies - brownies;
			}
		}
		while (icecream != 0) {                             //calculating icecream costs
			if (icecream >= 3) {
				cost = cost + (icecream / 3)*3.00;          // 3 for a 3 ic
				icecream = icecream % 3;
			}
			else if (icecream >= 2 && icecream < 3) {						 //2 for 2 ic
				cost = cost + (icecream / 2) * 2.00;
				icecream = icecream % 2;
			}
			else if (icecream == 1) {
				cost = cost + 1.50;                           //1.5 for 1 ic
				icecream = icecream - icecream;
			}
		}
		while (sundae != 0) {
			cost = cost + sundae * 2;
			sundae = sundae - sundae;
		}
		while (sandwich != 0) {
			cost = cost + sandwich * 2;
			sandwich = sandwich - sandwich;
		}
	}
	else if (!isWellFormedOrderString(order)) {                                // if not wellformed order, return 0.
		cost = 0.00;
		return 0;
	}
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	
	return cost;
}
//_________________________________________________
int main() {
	assert(!isWellFormedOrderString(""));        //test invalid empty string
	assert(!isWellFormedOrderString("12r"));      //test invalid char in string order
	assert(!isWellFormedOrderString("B"));      //test invalid single letter
	assert(!isWellFormedOrderString("33"));      //test invalid just integer
	assert(isWellFormedOrderString("13B"));          //test valid brownie entry
	assert(isWellFormedOrderString("3c"));        //test valid cookie entrie
	assert(!isWellFormedOrderString("3cc"));     //test invalid repeated char in string order
	assert(!isWellFormedOrderString("3c39b"));   //test invalid over 3 dozen order
	assert(isWellFormedOrderString("36C36b"));   //test valid cookie and brownie entry
	assert(!isWellFormedOrderString("36C1c12B")); //test invalid entry over 36 order of one item
	assert(!isWellFormedOrderString("+36C"));        //test invalid symbol
	assert(!isWellFormedOrderString("36c 36b"));    //test invalid space
	assert(!isWellFormedOrderString("12+-"));        //test invalid symbols
	assert(!isWellFormedOrderString("+-"));          //test invalid symbols
	assert(!isWellFormedOrderString("12+-12C"));    //test more invalid symbols
	assert(!isWellFormedOrderString("36C 12 B")); //test invalid spaces
	assert(!isWellFormedOrderString("37C37B"));     //test invalid entry over 36 of one item
	assert(!isWellFormedOrderString("09C2B"));          //test invalid 0 first entry
	assert(!isWellFormedOrderString("9C02B"));
	assert(!isWellFormedOrderString("1c        1c          2b")); //test invalid spaces
	assert(!isWellFormedOrderString("0c"));            //test invalid 0 order
	

	assert(calculateOrderCost("13c3i9d9s") == 44.00); //test calculate function
	assert(calculateOrderCost("23jkda9") == 0);        //test calculate function reading invalid
	assert(!calculateOrderCost("1c1c1C") == 0);        //test calcuate function reads that it's a proper string
	
	assert(!isWellFormedOrderString("37C"));
	assert(calculateOrderCost("37C") == 0.00);
	
	cerr << "All tests succeeded" << endl;

	string valueee;                                //testing calculations are correct
	cin >> valueee;
	cout << "$" << calculateOrderCost(valueee) << endl;

	return 0;
}