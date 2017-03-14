#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cassert>

using namespace std;

string findMaximum(const string array[], int n) {
	string biggest = "";                                   //initial empty string
	if (n <= 0)
		return "";
	for (int k = 0; k < n; k++) {                    //search through entire string array
		if (array[k] > biggest)
			biggest = array[k];
	}
	return biggest;
}
//________________________________________________________
bool hasDuplicatedValues(const string array[], int n) {
	bool duplicate = false;

	for (int k = 0; k < n; k++) {
		for (int l = 0; l < n; l++) {                //additional for loop to run through the array a second time
			if (k != l) {                               //ensures not measuring same string array slot
				if (array[k] == array[l])              //test for duplicate
					duplicate = true;
			}
		}
		return duplicate;
	}
}
//_______________________________________________________
int countAllVowels(const string array[], int n) {
	int vowels = 0;
	if (n <= 0)
		return -1;

	for (int k = 0; k < n; k++) {
		for (int l = 0; l < array[k].size(); l++) {                                 // check each strings' characters for a vowel a, e, i, o, u, y
			if (array[k][l] == 'a' || array[k][l] == 'e' || array[k][l] == 'i' || array[k][l] == 'o' || array[k][l] == 'u' || array[k][l] == 'y')
				vowels++;
		}
	}
	return vowels;
}
//_______________________________________________________
int countIntegers(const string array[], int n) {
	int integers = 0;
	if (n <= 0)
		return -1;

	for (int k = 0; k < n; k++) {
		bool onlydigits = true;
		for (int l = 0; l < array[k].length(); l++) {                  //if any character in a string isn't a digit, then not considered integer
			if (!isdigit(array[k][l]))
				onlydigits = false;
		}
		if (onlydigits == true)
			integers++;
	}
	return integers;
}
//_______________________________________________________
int moveToEnd(string array[], int n, int pos) {          //{ "daenerys", "jon", "tyrion", "samwell", "margaery" }
	if (n <= 0 || pos > n)
		return -1;

	string move = array[pos];                   // assume pos = 1 
	for (int k = pos; k < n - 1; k++) {                  //{ "daenerys", "jon", "tyrion", "samwell", "margaery" }       jon is stored in temporary 
		array[k] = array[k + 1];                   //{ "daenerys", "tyrion", "samwell", "margaery", "margaery" }        strings shifted over to let jon at end
	}
	array[n - 1] = move;                          //{ "daenerys", "tyrion", "samwell", "margaery", "jon" }
	return pos;
}
//______________________________________________________
int rotateRight(string array[], int n, int amount) {
	if (n <= 0)
		return -1;
	string last = array[n - 1];                                    // { "one", "two", "three", "four", "five" }     last = "five"
	for (int k = n - 1; k > 0; k--) {
		array[k] = array[k - 1];                                   // { "one", "one", "two", "three", "four" }     strings move over to right
	}
	array[0] = last;                                               // { "five", "one", "two", "three", "four" }    five inserted in beginning slot
	
	return n * amount;
}
//_______________________________________________________
int shiftLeft(string array[], int n, int amount, string placeholder) {
	if (n <= 0)
		return -1;
	if (amount < n) {                                 // {one, two, three, four, five, six}
		for (int k = 0; k < n - amount; k++)       //amount = 4
			array[k] = array[k + amount];             // {five, six, three four five six}
		for (int k = n - amount; k < n; k++)
			array[k] = placeholder;                     //{five, six, hello, hello, hello, hello}
		return amount;
	}
	else if (amount >= n) {
		for (int k = 0; k < n; k++)
			array[k] = placeholder;
		return n;
	}
}
//__________________________________________________________
int divide(string array[], int n, string divider) {
	if (n <= 0)
		return -1;
	string temporary = "";
	int returnvalue = n;


	for (int k = 0; k < n; k++) {                            // { "Evans", "Coltrane", "Monk", "Ellington", "Miles" } // divider = "Liszt"
		if (array[k] < divider) {                            //{ "Corea", "Marsalis", "Mingus", "Gershwin", "Guaraldi" } divider = "Gershwin"
			temporary = array[k];
			for (int l = k; l > 0; l--) {                   //if string is less than divider, move string to front.
				array[l] = array[l - 1];
			}
			array[0] = temporary;
		}
	}
	for (int k = 0; k < n; k++) {                               // looks for divider inside array and puts it in the correct position
		if (array[k] == divider && array[k - 1] > divider) {                //if divider is on the side with the "less than" strings
			string switchthis = array[k];
			for (int l = 0; l < n; l++) {
				if (array[l] > divider && array[l - 1] < divider) {
					array[k] = array[l];
					array[l] = switchthis;
				}
			}
		}
		else if (array[k] == divider && array[k + 1] < divider) {    //if divider is on the side with the "greater than" strings
			string switchthis = array[k];
			for (int l = 0; l < n; l++) {
				if (array[l] < divider && array[l + 1] > divider) {
					array[k] = array[l];
					array[l] = switchthis;
				}
			}
		}
	}
	for (int a = n; a > 0; a--) {                  //order strings in array to be alphabetical order
		int maxvalue;
		string max = findMaximum(array, a);
		for (int k = 0; k < a; k++) {
			if (array[k] == max)                  //find where the max value in array is located
				maxvalue = k;
		}
		temporary = array[maxvalue];                 //put max value in temporary variable
		for (int l = maxvalue; l < a - 1; l++)
			array[l] = array[l + 1];                 //move variables to the left
		array[a - 1] = temporary;                    //put max value at the back.
	}
	for (int k = 0; k < n; k++) {                          //calculating return value
		if (array[k] >= divider) {
			returnvalue = k;
			break;
		}
	}
	return returnvalue;
}


int main() {
	string a[5] = { "daenerys", "jon", "tyrion", "samwell", "margaery" };         //function 1
	string acap[5] = { "a", "apple", "Apple", "App", "APPLE" };                   //APPLE App Apple a apple
	assert(findMaximum(a, 5) == "tyrion");      
	assert(findMaximum(acap, 5) == "apple");

	string b[4] = { "howard", "ucla", "howard", "ucla" };
	assert(!hasDuplicatedValues(b, 2));                    //function 2
	assert(hasDuplicatedValues(b, 4));

	string c[5] = { "samwell", "jon", "margaery", "daenerys", "tyrion" };
	assert(countAllVowels(c, 5) == 14);                   //function 3
	assert(countAllVowels(c, 0) == -1);

	string d[5] = { "one", "2", "three", "004", "five" };
	string d2[5] = { "10", "1", "0", "50050402304293", ".02" };
	assert(countIntegers(d, 5) == 2);                         //function 4
	assert(countIntegers(d, 2) == 1);
	assert(countIntegers(d, 0) == -1);
	assert(countIntegers(d2, 5) == 4);


	string e[5] = { "daenerys", "jon", "tyrion", "samwell", "margaery" };
	assert(moveToEnd(e, 5, 2) == 2);                         //function 5
	assert(moveToEnd(e, 0, 1) == -1);
	assert(moveToEnd(e, 5, 8) == -1);
	//cout << e[0] << " " << e[1] << " " << e[2] << " " << e[3] << " " << e[4] << endl;
	
	string f[5] = { "one", "two", "three", "four", "five" };              //function 6
	assert(rotateRight(f, 5, 3) == 15);                   
	//cout << f[0] << " " << f[1] << " " << f[2] << " " << f[3] << " " << f[4] << endl;
	assert(rotateRight(f, -2, 3) == -1);

	string g[6] = { "one", "two", "three", "four", "five", "six" };       //function 7
	assert(shiftLeft(g, 6, 4, "hello") == 4); 
	//cout << g[0] << " " << g[1] << " " << g[2] << " " << g[3] << " " << g[4] << " " << g[5] << endl;
	assert(shiftLeft(g, 6, 10, "hello") == 6);
	//cout << g[0] << " " << g[1] << " " << g[2] << " " << g[3] << " " << g[4] << " " << g[5] << endl;
	assert(shiftLeft(g, 0, 10, "hello") == -1);

	string h[5] = { "Evans", "Coltrane", "Monk", "Ellington", "Miles" };		  //function 8
	assert(divide(h, 5, "Liszt") == 3);
	cout << h[0] << " " << h[1] << " " << h[2] << " " << h[3] << " " << h[4] << endl;
	assert(divide(h, -10, "david") == -1);

	string i[5] = { "Corea", "Marsalis", "Mingus", "Gershwin", "Guaraldi" };
	assert(divide(i, 5, "Gershwin") == 1);
	cout << i[0] << " " << i[1] << " " << i[2] << " " << i[3] << " " << i[4] << endl;

	string j[] = { "a", "b", "e", "p", "divider", "alphabet", "LOL", "A", "zeelast", "divider", "lol" };
	assert(divide(j, 11, "divider") == 5);
	for (int lol = 0; lol < 11; lol++) {
		cout << j[lol] << " ";
	}
	cout << endl;
	cerr << "All tests succeeded." << endl;


	return 0;
}
