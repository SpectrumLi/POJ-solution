#include <iostream>
#include <stdlib.h>
#include <string>

#define MAXN 23000

using namespace std;

int ans[MAXN];

int main() {
	int j;
	int p, e, i, d;
	int index = 0;
	while (cin >> p >> e >> i >> d) {
		index++;
		if (p < 0) break;
		for (j = 0; j < MAXN; j++)
			ans[j] = 0;
		int rp, re, ri;
		rp = p % 23;
		re = e % 28;
		ri = i % 33;
		while (rp < MAXN) {
			ans[rp]++;
			rp += 23;
		}
		while (re < MAXN) {
			ans[re]++;
			re += 28;
		}
		while (ri < MAXN) {
			ans[ri]++;
			ri += 33;
		}
		for (j = d+1; j < 23000; j++)
			if (ans[j] == 3) break;
		cout << "Case " << index << ": the next triple peak occurs in " << j - d << " days. " << endl;
	}
	return 0;
}