//
//  SlotMachine.cpp
//  SlotMachine
//
//  Created by Howard Stahl on 7/9/16.
//  Copyright © 2016 Howard Stahl. All rights reserved.
//


#include <cstdlib>
#include <iostream>
#include <string>
#include "SlotMachine.h"
#include "RandomNumber.h"
#include "Bank.h"


SlotMachine::SlotMachine(char w1, char w2, char w3, std::string seq, int startingBankBalance)
	: wheel1(w1), wheel2(w2), wheel3(w3), sequence(seq)
{
	bank.deposit(startingBankBalance);
}

// end the game
void SlotMachine::quit()
{
	exit(0);
}

// accessor for this machine's Bank
Bank SlotMachine::getBank() const
{
	return(bank);
}

// TO DO:
// set the wager on this machines' Bank
void SlotMachine::bet(int amount)
{
	bank.setWager(amount);
}

// TO DO:
// determines whether the wheels are a winning play or not
// returning 0 indicates the player lost their bet
// returning 1 indicates the player won their bet back
// returning a value larger than 1 indicates the player won a multiple of their bet back
//     say, two times, three times, ten times and so on
// implement the pay table documented in the assignment
// the supplied code is wrong and is there just to allow the skeleton to compile
int SlotMachine::evaluateWheels()
{
	int returnvalue = 0;
	if (wheel1 == 'A' && wheel2 == 'A' && wheel3 == 'A')                      // 3 matching A's
		returnvalue = 10;
	else if (wheel1 == wheel2 && wheel1 == wheel3 && wheel1 != 'A')           // 3 matching items (not A's)
		returnvalue = 7;
	else if (wheel1 == 'A' && wheel2 == 'A' && wheel3 != 'A')                // 2 matching A's
		returnvalue = 5;
	else if (wheel1 == 'A' && wheel2 != 'A' && wheel3 == 'A')
		returnvalue = 5;
	else if (wheel1 != 'A' && wheel2 == 'A' && wheel3 == 'A')
		returnvalue = 5;
	else if (wheel1 == wheel2 && wheel1 != wheel3 && wheel1 != 'A' && wheel3 != 'A')  //one pair match that isn't Ace
		returnvalue = 3;
	else if (wheel1 == wheel3 && wheel1 != wheel2 && wheel1 != 'A' && wheel2 != 'A')
		returnvalue = 3;
	else if (wheel2 == wheel3 && wheel2 != wheel1 && wheel2 != 'A' && wheel1 != 'A')
		returnvalue = 3;
	else if (wheel1 == wheel2 && wheel1 != wheel3 && wheel1 != 'A' && wheel3 == 'A')  //one pair match that isn't Ace with an Ace
		returnvalue = 4;
	else if (wheel1 == wheel3 && wheel1 != wheel2 && wheel1 != 'A' && wheel2 == 'A')
		returnvalue = 4;
	else if (wheel2 == wheel3 && wheel2 != wheel1 && wheel2 != 'A' && wheel1 == 'A')
		returnvalue = 4;
	else if ((wheel1 == 'A' && wheel2 == 'K' && wheel3 == 'Q')||(wheel1 == 'Q' && wheel2 == 'K' && wheel3 == 'A')) //AKQ or QKA
		returnvalue = 5;
	else if ((wheel1 != 'A' && wheel2 != 'A' && wheel3 == 'A') && (!(wheel1 == 'A' && wheel2 == 'K' && wheel3 == 'Q') || (wheel1 == 'Q' && wheel2 == 'K' && wheel3 == 'A')))           // one A
		returnvalue = 1;
	else if ((wheel1 != 'A' && wheel2 == 'A' && wheel3 != 'A') && (!(wheel1 == 'A' && wheel2 == 'K' && wheel3 == 'Q') || (wheel1 == 'Q' && wheel2 == 'K' && wheel3 == 'A')))
		returnvalue = 1;
	else if ((wheel1 == 'A' && wheel2 != 'A' && wheel3 != 'A') && (!(wheel1 == 'A' && wheel2 == 'K' && wheel3 == 'Q') || (wheel1 == 'Q' && wheel2 == 'K' && wheel3 == 'A')))
		returnvalue = 1;

	return returnvalue;
}

// TO DO:
// called by display() once the wheels have stopped spinning
// based on this slot machine's bank's wager and after evaluating the wheels of this machine,
// adjust the bank to indicate whether a win or loss occurred
void SlotMachine::manageWager()
{
	if (evaluateWheels() >= 1)
		bank.win(bank.getWager() * evaluateWheels());
	if (evaluateWheels() == 0)
		bank.lose(bank.getWager());
}


///////////////////////////////////////////////////////////////////////////
//  play implementation
///////////////////////////////////////////////////////////////////////////
// CS 31 Students do not need to change anything here

void SlotMachine::play()
{
	using namespace std;
	do
	{
		cout << endl;
		cout << "Move (d#/b#/p/c/q): ";
		string action;
		string message;
		int amount;
		getline(cin, action);
		if (action.size() == 0)
		{
			quit();
		}
		else
		{
			switch (action[0])
			{
			default:   // if bad move, nothing happens
				cout << '\a' << endl;  // beep
				continue;
			case 'q':
				return;
				break;

			case 'b':  // get
				amount = atoi(action.substr(1).c_str());
				if (amount == 0)
					amount = 1;
				if (bank.canWager(amount))
				{
					bet(amount);
					cout << "$" << amount << " Bet Accepted!" << endl;
				}
				else
				{
					cout << "Invalid Bet" << endl;
				}
				break;
			case 'p':
				if (bank.getWager() == 0)
				{
					cout << "You Must Bet First Before Playing" << endl;
				}
				else
				{
					display();
				}
				break;
			case 'd':
				amount = atoi(action.substr(1).c_str());
				if (amount == 0)
				{
					cout << "Invalid Bank Deposit" << endl;
				}
				else
				{
					bank.deposit(amount);
					cout << "$" << bank.balance() << " Available To Bet" << endl;
				}
				break;
			case 'c':
				amount = bank.cashOut();
				cout << "$" << amount << " Returned To You!" << endl;
				amount = 0;
				break;
			}
		}

	} while (true);
}


///////////////////////////////////////////////////////////////////////////
//  display implementation
///////////////////////////////////////////////////////////////////////////
// CS 31 Students do not need to change anything here

void SlotMachine::display()
{
	using namespace std;
	// Draw the machine
	int w1 = 0, w2 = 0, w3 = 0;
	RandomNumber r(0, static_cast<int>(sequence.length() - 1));
	for (int i = 0; i <= static_cast<int>(sequence.length() - 1); i++)
	{
		clearScreen();
		w1 = r.random();
		cout << endl;
		cout << sequence[w1] << endl;
		cout << endl;
		pause();
	}
	clearScreen();
	wheel1 = sequence[w1];
	cout << wheel1 << endl;
	for (int j = 0; j <= static_cast<int>(sequence.length() - 1); j++)
	{
		clearScreen();
		w2 = r.random();
		cout << endl;
		cout << wheel1 << " " << sequence[w2] << endl;
		cout << endl;
		pause();
	}
	clearScreen();
	wheel2 = sequence[w2];
	cout << wheel1 << " " << wheel2 << endl;
	for (int k = 0; k <= static_cast<int>(sequence.length() - 1); k++)
	{
		clearScreen();
		w3 = r.random();
		cout << endl;
		cout << wheel1 << " " << wheel2 << " " << sequence[w3] << endl;
		cout << endl;
		pause();
	}
	clearScreen();
	wheel3 = sequence[w3];
	cout << endl;
	cout << wheel1 << " " << wheel2 << " " << wheel3 << endl;
	int balanceBefore = bank.balance();
	int wager = bank.getWager();
	manageWager();
	int balanceAfter = bank.balance();
	if (balanceBefore > balanceAfter)
	{
		cout << "Lost $" << wager << endl;
	}
	else
	{
		cout << "Won $" << balanceAfter - balanceBefore << endl;
	}
	cout << "$" << bank.balance() << " Available To Bet" << endl;
}


///////////////////////////////////////////////////////////////////////////
//  clearScreen and pause implementations
///////////////////////////////////////////////////////////////////////////

// DO NOT MODIFY OR REMOVE ANY CODE BETWEEN HERE AND THE END OF THE FILE!!!
// THE CODE IS SUITABLE FOR VISUAL C++, XCODE, AND g++ UNDER LINUX.

// Note to Xcode users:  clearScreen() will just write a newline instead
// of clearing the window if you launch your program from within Xcode.
// That's acceptable.

#ifdef _MSC_VER  //  Microsoft Visual C++

#include <windows.h>

void SlotMachine::clearScreen()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	COORD upperLeft = { 0, 0 };
	DWORD dwCharsWritten;
	FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperLeft,
		&dwCharsWritten);
	SetConsoleCursorPosition(hConsole, upperLeft);
}

void SlotMachine::pause()
{
	Sleep(200);
}

#else  // not Microsoft Visual C++, so assume UNIX interface

#include <cstring>
#include <thread>
#include <chrono>


void SlotMachine::clearScreen()  // will just write a newline in an Xcode output window
{
	using namespace std;
	static const char* term = getenv("TERM");
	if (term == nullptr || strcmp(term, "dumb") == 0)
		cout << endl;
	else
	{
		static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
		cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
	}
}

void SlotMachine::pause()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(200));
}

#endif
