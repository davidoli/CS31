// slotmachine.cpp

// Portions you are to complete are marked with a TODO: comment.
// We've provided some incorrect return statements (so indicated) just
// to allow this skeleton program to compile and run, albeit incorrectly.
// The first thing you probably want to do is implement the trivial
// functions (marked TRIVIAL).  As you finish implementing each TODO: item,
// remove its TODO: comment.

#include "SlotMachine.h"
#include <iostream>
#include <cassert>
#include <string>

///////////////////////////////////////////////////////////////////////////
//  main()
///////////////////////////////////////////////////////////////////////////
using namespace std;

int main()
{
	Bank b;             // wager and bankAmount = 0 
	assert(b.balance() == 0);       // returns 0 
	assert(!b.canWager(100));  // returns false because there aren't sufficient funds in this Bank 
	b.deposit(50);
	b.balance();       // returns 50 
	assert(!b.canWager(100));  // returns false because there aren't sufficient funds in this Bank 
	b.deposit(50);
	assert(b.canWager(100));  // returns true because there are sufficient funds 
	b.setWager(100);  // $100 has now been bet  
	assert(b.getWager() == 100);      // returns 100 
	assert(b.balance()==100);       // returns 100 because the bet wager has not yet been won or lost 
	b.win(100);       // the wager was won 
	assert(b.cashOut()==200);       // returns 200

	SlotMachine s('Q', 'K', '8', "AKQJ987", 100);   // cheating...
	b = s.getBank();
	assert(b.balance() == 100);
	assert(b.getWager() == 0);
	assert(b.canWager(100));
	s.bet(100); 
	cout << s.evaluateWheels() << endl; 
	assert(s.evaluateWheels() == 0);               // 3 Aces is 10-1 winner
	s.manageWager();                                  // evaluate this winning hand which adjusts the bank...
	b = s.getBank();
	assert(b.balance() == 000);

	cerr << "all tests succeeded" << endl;

	// Create a slot machine
	SlotMachine d;

	d.evaluateWheels();
	// Play the slot machine
	d.play();
	return(0);
}





