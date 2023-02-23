/*
 * EZ Tip Calculator - a simple resturaunt tip calculator by Mac Young
 * February 22, 2023
 */
#include <iostream>	// cout, cin, streamsize
#include <cmath>	// ceil
#include <iomanip>	// fixed, setprecision
#include <limits>	// numeric_limits
#include <fstream>	// ofstream

// Prototypes. Information about them are detailed at the time they are called.
void tip_calc(double bill, int split);
void data_retrieval();

// MAIN
int main() {
	data_retrieval();
	return 0;
}

// data_retrieval gets information from the user, such as the cost of the bill, what percent of the bill the user would
// like to add for a tip, and how many members of the party to split the total with.
void data_retrieval() {
	double b, p, n = 1;	// bill, percent, new total
	int s = 1, status = 0;	// split, status

	std::cout<<"EZ Tip Calculator by Mac Young!\nLicensed under the Zero-BSD License, this software is Free and Open Source Software.\n\n";
	std::cout<<"Please insert whole numbers, and round up! Don't be a cheapskate.\n\n";
	
	// Status is meant to indicate how far we are in the information gathering cycle.
	while (status < 3) {
		switch (status) {
			case 0:
				std::cout<<"Total cost of the bill > ";
				std::cin>>b;
				break;
			case 1:
				std::cout<<"Percent of your bill to tip > ";
				std::cin>>p;
				break;
			case 2:
				std::cout<<"Split the bill across how many people? (Enter 1 if you ate alone.) > ";
				std::cin>>s;
				break;
		}
		// If the user forked over trash, we'll just have to flush it and ask the user again.
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		// The bill and the party count can't be 0.
		else if(b <= 0 || s <= 0) {
			std::cerr<<"This must be greater than 0.\n";
			continue;
		}
		// Next!
		status++;
		// If we got the bill and the percent to tip from the user, we can tell the user approximately
		// how much the new total is.
		if (status == 2) {
			n = ceil(b * (p / 100) + b);
			std::cout<<"Your bill plus the tip is $"<<std::fixed
				<<std::setprecision(2)<<n<<".\n";
		}
	}
	// Calculate how much each person must pay, and we are good to go!
	tip_calc(n, s);
	return;
}

// tip_calc takes the total cost of the bill plus the tip, as well as how many people in the party, and reveals
// how much each memeber of that party should pay. It then drops a receipt file detailing how much money was 
// spent last time this program was ran.
void tip_calc(double bill, int split) {
	std::cout<<"\nYour bill: $"<<bill<<" spit across "<<split<<" way(s) is:\n\t$"<<std::fixed
		<<std::setprecision(2)<<ceil(bill / split)<<"\n";

	std::ofstream receipt("receipt.txt");
	receipt<<"You paid $"<<std::fixed<<std::setprecision(2)<<ceil(bill / split)<<" last time.\n";
	receipt.close();
	std::cout<<"\nA receipt has been made for you. Read the \"receipt.txt\" for today's tip transaction.\n";
	return;
}
