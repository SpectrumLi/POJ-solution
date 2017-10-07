#include <iostream>
#include <stdlib.h>
#include <string>
#include <iomanip>

using namespace std;

int main() {
	float s, x;
	int i;
	s = 0;
	for (i = 0; i < 12; i++) {
		cin >> x;
		s += x;
	}
	float ans = s / 12;
	cout <<"$"<<fixed<< setprecision(2)<< ans << endl;
	return 0;
}