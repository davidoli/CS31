#include <iostream>
#include <string>

using namespace std;

int main() {
	double bill;
	string name;
	double water;
	string type;
	
	cout << "Customer Name: ";
	getline(cin, name);                  //input name value
	
	if (name == "") {
		cout << "--- You must enter a customer name." << endl;
		return 0;
	}
	else {
		cout << "Water Used (in HCF): "; //input water value
		cin >> water;
		cin.ignore(10000, '\n');

		if (water < 0) {
			cout << "--- The water used must be nonnegative." << endl;
			return 0;
		}
		else {
			cout << "Customer Type: ";  //customer value
			getline(cin, type);

			//calculate water
			if (type == "Business" || type == "business") {                       //Business water calculations
				if (water <= 5.0 && water >= 0.0) {
					bill = 5.95 + 4.5*water;
				}
				else if (water > 5.0 && water <= 15.0) {
					bill = 5.95 + 4.5*5.0 + 7.0*(water - 5.0);
				}
				else if (water > 15.0 && water <= 30.0) {
					bill = 5.95 + 4.5*5.0 + 7.0*10.0 + 13.25*(water - 15.0);
				}
				else if (water > 30.0) {
					bill = 5.95 + 4.5*5.0 + 7.0*10.0 + 13.25*15.0 + 15.99*(water - 30.0);
				}
			}
			else if (type == "Residential" || type == "residential") {            //Residents water calculations
				if (water <= 5 && water >= 0) {
					bill = 5.95 + 3.00*water;
				}
				else if (water > 5 && water <= 15) {
					bill = 5.95 + 3.00 * 5 + 5.25*(water - 5);
				}
				else if (water > 15 && water <= 30) {
					bill = 5.95 + 3.00 * 5 + 5.25 * 10 + 10.00*(water - 15);
				}
				else if (water > 30) {
					bill = 5.95 + 3.00 * 5 + 5.25 * 10 + 10.00 * 15 + 12.75*(water - 30);
				}
			}
			
			else if (type != "Business" && type != "Residential" && type != "business" && type != "residential") {
				cout << "--- The customer type is not valid." << endl;
				return 0;
			}
		}
	}
	if (water >= 0 && name != "" && type == "Business" || type == "Residential" || type == "business" || type == "residential") {
		
		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(2);

		cout << "--- The bill for " << name << " is $" << bill << endl;
	}
	return ( 0 );
}