//
//  Bank.cpp
//  SlotMachine
//
//  Created by Howard Stahl on 7/9/16.
//  Copyright © 2016 Howard Stahl. All rights reserved.
//

#include "Bank.h"


// TO DO:
// set the credits to the parameter amount and zero out the wager
Bank::Bank(int amount)
{
	credits = amount;
	wager = 0;
}

// TO DO:
// adjust the credits for this win and zero out the wager
void Bank::win(int amount)
{
	credits = credits + amount;
	wager = 0;
}

// TO DO:
// adjust the credits for this loss and zero out the wager
void Bank::lose(int amount)
{
	credits = credits - amount;
	wager = 0;
}

// TO DO:
// accept additional credits
void Bank::deposit(int amount)
{
	credits = credits + amount;
}

// TRIVIAL:
// accessor for credits member
// the supplied code is wrong and is there just to allow the skeleton to compile
int Bank::balance() const
{
	return(credits);
}

// TO DO:
// return all this bank's credits to the caller and zero out the wager and credit as a result
// the supplied code is wrong and is there just to allow the skeleton to compile
int Bank::cashOut()
{
	int cashout = credits;
	credits = 0;
	wager = 0;
	return(cashout);
}

// TO DO:
// is this bank's credit large enough to allow a wager of the parameter amount
// the supplied code is wrong and is there just to allow the skeleton to compile
bool Bank::canWager(int amount) const
{
	bool wager;
	if (amount > credits)
		wager = false;
	else if (amount <= credits)
		wager = true;
	return wager;
}

// TRIVIAL:
// mutator for wager member
void Bank::setWager(int amount)
{
	wager = amount;
}

// TRIVIAL:
// accessor for wager member
// the supplied code is wrong and is there just to allow the skeleton to compile
int Bank::getWager() const
{
	return(wager);
}
