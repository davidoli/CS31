//
//  Bank.hpp
//  SlotMachine
//
//  Created by Howard Stahl on 7/9/16.
//  Copyright © 2016 Howard Stahl. All rights reserved.
//

#ifndef Bank_h
#define Bank_h

// this class keeps track of a slot machine's credit and wager
// the credit held in this Bank is stored in the member: credits
// the amount bet by this Bank is stored in the member: wager
// as the SlotMachine's play and display cycle occurs, the various
// public methods shown below are called
class Bank
{
public:
	// by default, the bankAmount and wager should both be zero
	Bank(int amount = 0);

	// increase this Bank's credits by this amount
	void win(int amount);
	// decrease this Bank's credits by this amount
	void lose(int amount);

	// add credits to this Bank
	void deposit(int amount);
	// accessor for the credit member
	int balance() const;
	// return all credits and zero out this Bank
	int cashOut();


	// mutator for the wager member
	void setWager(int amount);
	// accessor for the wager member
	int getWager() const;
	// can this Bank accept a wager this large?
	bool canWager(int amount) const;

private:
	int credits;
	int wager;

};


#endif /* Bank_h */
