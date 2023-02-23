#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
#include <fstream>

void tip_calc(double bill, int split);
void data_retrieval();

int main() {
	data_retrieval();
	return 0;
}

void data_retrieval() {
	double b, p, n = 0.01;
	int s = 1;
	int status = 0;

	std::cout<<"EZ Tip Calculator by Mac Young!\nLicensed under the Zero-BSD License, this software is Free and Open Source Software.\n\n";

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
				std::cout<<"Split the bill across how many people? > ";
				std::cin>>s;
				break;
		}
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		else if(b <= 0 || s <= 0) {
			std::cerr<<"This must be greater than 0.\n";
			continue;
		}
		status++;
		if (status == 2) {
			n = b * (p / 100) + b;
			std::cout<<"Your bill plus the tip is $"<<std::fixed
				<<std::setprecision(2)<<n<<".\n";
		}
	}
	tip_calc(n, s);
	return;
}

void tip_calc(double bill, int split) {
	std::cout<<"\nYour bill: $"<<bill<<" spit across "<<split<<" way(s) is:\n\t$"<<std::fixed
		<<std::setprecision(2)<<ceil(bill / split)<<".\n";
	return;
}
