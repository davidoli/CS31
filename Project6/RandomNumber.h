//
//  RandomNumber.hpp
//  SlotMachine
//
//  Created by Howard Stahl on 7/9/16.
//  Copyright © 2016 Howard Stahl. All rights reserved.
//

#ifndef RandomNumber_h
#define RandomNumber_h

class RandomNumber
{
public:
	// supply a number between min and max inclusive
	RandomNumber(int min, int max, bool minInclusive = true, bool maxInclusive = true);
	int random();  // pull a random number in the desired range

private:
	int mMinimum;  // the smallest random number desired
	int mMaximum;  // the largest random number desired
};


#endif /* RandomNumber_h */
