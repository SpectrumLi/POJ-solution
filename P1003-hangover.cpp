#include <iostream>
#include <stdlib.h>
#include <string>
#define MAXN 10000

using namespace std;

float a[MAXN];

int dividesearch(int x, int y, float f);
int main() {
	a[0] = 0;
	int i;
	int n;
	for (i = 1; i < MAXN; i++) {
		a[i] = a[i - 1] + 1 / ((i + 1)*1.0);
		if (a[i] > 5.20) {
			n = i;
			break;
		}
	}
	//cout << n << endl;
	float x;
	while (cin >> x) {
		if (x < 0.00001) break;
		int ans = dividesearch(1, n, x);
		cout << ans << " card(s)" << endl;
	}
	return 0;
}
int dividesearch(int x, int y, float f) {
	if (x == y)
		return x;
	int z = (x + y) / 2;
	if (a[z] > f)
		return dividesearch(x,z,f);
	else
		return dividesearch(z+1,y,f);
}