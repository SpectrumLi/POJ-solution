#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector <float> ans;
vector <float> r;

int dfind(int x, int y,float k);

int main() {
	int n;
	float ldis = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		float x, y;
		cin >> x >> y;
		float z = sqrt(x*x + y*y);
		if (z > ldis) ldis = z;
		r.push_back(z);
	}
	float cr = 0;
	int m = 0;
	
	while (cr < ldis) {
		cr = sqrt(100 / 3.141592653589793238463 + cr*cr);
		ans.push_back(cr);
		m++;
	}
	//cout << m << " years is calculated" << endl;
	int i = 0;
	for (vector<float>::iterator it = r.begin(); it != r.end(); it++) {
		float y = *it;
		//cout << "search " << y << endl;
		int x = dfind(0,m-1,y);
		i++;
		cout << "Property " << i << ": This property will begin eroding in year " << x+1 << "." << endl;
	}
	cout<<"END OF OUTPUT."<<endl;
	return 0;
}
int dfind(int x, int y, float k) {
	if (x == y)
		return x;
	int z = (x + y) / 2;
	if (ans[z] > k)
		return dfind(x,z,k);
	else
		return dfind(z+1,y,k);
}


