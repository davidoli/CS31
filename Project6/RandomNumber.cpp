//
//  RandomNumber.cpp
//  SlotMachine
//
//  Created by Howard Stahl on 7/9/16.
//  Copyright © 2016 Howard Stahl. All rights reserved.
//

#include "RandomNumber.h"


#include <random>
#include <utility>

using namespace std;

// Specify the range of the random numbers desired
RandomNumber::RandomNumber(int min, int max,
	bool minInclusive, bool maxInclusive)
	: mMinimum(min), mMaximum(max)
{
	if (mMinimum > mMaximum)
	{
		swap(mMinimum, mMaximum);
	}
	if (!minInclusive)
	{
		mMinimum++;
	}
	if (!maxInclusive)
	{
		mMaximum--;
	}
}

// CS 31 Students don't need to worry about the code shown below
// the effect of this code is that it delivers a random value back to the caller
int RandomNumber::random()
{
	static random_device rd;
	static mt19937 generator(rd());
	uniform_int_distribution<> distro(mMinimum, mMaximum);

	return(distro(generator));
}
