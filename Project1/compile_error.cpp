// Code for Project 1
// Report weather results

#include <iostream>
using namespace std;   // pp. 37-38 in Savitch book explain this line

int main()
{
	int daysRevi ewed;
	int daysCloudy;
	int daysAbove100Degrees;

	cout << "How many days were reviewed? ";
	cin >> daysReviewed;
	cout << "How many of these days were cloudy? ";
	cin >> daysCloudy;
	cout << "How many of these days were hotter than 100 degrees? ";
	cin >> daysAbove100Degrees;

	double pctCloudy = 100.0 * daysCloudy / daysReviewed
	double pctHot = 100.0 * daysAbove100Degrees / daysReviewed;

	cout.setf(ios::fixed);       // see pp. 30-31 in Savitch book
	cout.precision(1);

	cout << endl;
	cout << pctCloudy << "% were cloudy." << endl;
	cout << pctHot << "% were hot." << endl;

	if (pctCloudy > pctHot)
		cout << "It was cloudy more often than it was hot." << endl;
	else
		cout << "It was hot more often than it was cloudy." << endl;
}