//
//  SlotMachine.hpp
//  SlotMachine
//
//  Created by Howard Stahl on 7/9/16.
//  Copyright © 2016 Howard Stahl. All rights reserved.
//

#ifndef SlotMachine_h
#define SlotMachine_h

#include "Bank.h"
#include <string>

class SlotMachine
{
public:
	SlotMachine(char w1 = 'A', char w2 = 'A', char w3 = 'A', std::string seq = "AKQJ9876", int startingBankBalance = 0);

	// determines whether the wheels are a winning play or not
	// returning 0 indicates the player lost their bet
	// returning 1 indicates the player won their bet back
	// returning a value larger than 1 indicates the player won a multiple of their bet back
	//     say, two times, three times, ten times and so on
	// this method should implement the pay table documented in the assignment
	int evaluateWheels();

	// called by play() to indicate the amount the player wishes to bet on the next pull
	// adjusts the bank for the amount the player wishes to bet
	void bet(int amount);

	// called by display() once the wheels have stoped spinning
	// adjust the bank by calling evaluateWheels to determine if a win or loss occurred
	void manageWager();

	// accessor for this slot machine's bank
	Bank getBank() const;

	// ends the program
	void quit();
	// interacts with the user to allow for additional machine credits, betting, cashing out and quitting
	void play();
	// spins the wheels and adjusts the bank based on what happens
	void display();


	///////////////////////////////////////////////////////////////////////////
	//  Auxiliary function declarations for screen manipulation
	///////////////////////////////////////////////////////////////////////////
	void clearScreen();
	void pause();

private:
	char wheel1, wheel2, wheel3;
	std::string sequence;
	Bank bank;
};


#endif /* SlotMachine_h */
