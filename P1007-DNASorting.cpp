#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int main() {
	int n, m;
	string st[100];
	int c[100];
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		st[i] = s;
		int sum = 0;
		for (int x = 0; x<m; x++)
			for (int y = x+1; y < m; y++)
				if (s[y] < s[x]) sum++;
		c[i] = sum;
	}
	for (int x = 0; x<n;x++)
		for (int y = x+1; y<n; y++)
			if (c[y] < c[x]) {
				int z; z = c[y]; c[y] = c[x]; c[x] = z;
				string ss; ss = st[y]; st[y] = st[x]; st[x] = ss;
			}
	for (int x = 0; x < n; x++)
		cout << st[x] << endl;
}