#include <iostream>
#include <string>
#include <stdlib.h>
#define LEN 100000
using namespace std;

void work(string r, string n);
void print(int x[], int p);
int ans[LEN];
int ans2[LEN];
int *anstemp;
int main() {
	string r, n;
	while (cin >> r >> n) {
		work(r, n);
	}
	return 0;
}

void work(string s1, string s2) {
	int n = atoi(s2.c_str());
	//cout << s1 << n << endl;
	int x[LEN];
	for (int i = 0; i < LEN; i++) {
		ans[i] = 0;
		x[i] = 0;
	}
	ans[0] = 1;
	ans[1] = 1;
	int p = 0;
	int pp = 0;
	
	x[0] = 0;
	for (int i = s1.length() - 1; i >= 0; i--) {
		//if (s1[i] == ' ') continue;
		if (s1[i] == '.') {
			pp = 1;
		}
		else {
			x[x[0] + 1] = s1[i] - '0';
			x[0] ++;
			if (pp == 0) p++;
		}
	}
	pp = 0;
	int * res = ans2;
	int * mul = ans;
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < LEN; i++) res[i] = 0;
		//cout << "---------" << endl;
		//print(ans, pp);
		//print(x, p);
		for (int i = 1; i <= mul[0]; i++)
			for (int j = 1; j <= x[0]; j++) {
				res[i + j - 1] += mul[i] * x[j];
				//cout << res[i + j - 1] << " ";
			}
		for (int i = 1; i < mul[0] + x[0] - 1; i++) {
			res[i + 1] += res[i] / 10;
			res[i] = res[i] % 10;
		}
		int i = mul[0] + x[0] - 1;
		while (res[i] > 10) {
			res[i + 1] += res[i] / 10;
			res[i] = res[i] % 10;
			i++;
		}
		res[0] = i;
		int * temp = res;
		res = mul;
		mul = temp;
		pp += p;
		//print(temp, pp);
	}
	print(mul, pp);
	return;
}

void print(int x[], int p) {
	//cout << "P is " << p << endl;
	//int temp = x[0] - p;
	int last,first;
	for (last = 1; last <= p; last++)
		if (x[last] > 0) break;
	for (first = x[0]; first > p; first--)
		if (x[first] > 0) break;
	for (int i = first; i >= last; i--) {
		if (i == p)
			cout << ".";
		cout << x[i];
	}
	cout << endl;
}