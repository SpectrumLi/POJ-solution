#include <iostream>
#include <stdlib.h>
#include <string>
#include <map>
#include <stdio.h>
#define MAXN 10000000

using namespace std;

//int ans[MAXN];
int r[26] = { 2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9,0 };
map <int, int> mp;
int trans(string s);
void print(int x, int y);

int main() {
	int n;
	//for (int i = 0; i < MAXN;i++)
	//	ans[i] = 0;
	string s;
	cin >> n;
	for (int l = 0; l < n ; l++){
		cin >> s;
		//int x = trans(s);
		//if (mp.find(x) == mp.end()) mp[x] = 1;
		//else mp[x] = mp[x] + 1;
		int x = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '-') continue;
			int y = s[i] - '0';
			if ((s[i] <= 'Z') && (s[i] >= 'A')) y = r[s[i] - 'A'];
			x = x * 10 + y;
		}
		mp[x]++;
	}
	int flag = 0;
	//for (int i = 0; i < MAXN; i++)
	//	if (ans[i] > 1) {
	//		print(i, ans[i]);
	//		flag = 1;
	//	}
	map<int, int>::iterator it = mp.begin();
	while (it != mp.end()) {
		if (it->second > 1) {
			//print(it->first, it->second);
			printf("%03d-%04d %d\n", it->first / 10000, it->first % 10000, it->second);
			flag = 1;
		}
		it++;
	}
	if (flag == 0) {
		cout << "No duplicates."<<endl;
	}
	return 0;
}

void print(int x, int y) {
	/*string st = "";
	for (int k = 0; k < 7; k++) {
		char ch = x % 10 + '0';
		st = ch + st;
		if (k == 3) st = "-" + st;
		x = x / 10;
	}
	cout << st << " " << y << endl;
	*/
	printf("%03d-%04d %d\n", x/10000,x % 10000,y);
	return;
}

int trans(string s) {
	int x = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '-') continue;
		int y = s[i] - '0';
		if ((s[i] <= 'Z') && (s[i] >= 'A')) y = r[s[i] - 'A'];
		x = x * 10 + y;
	}
	return x;
}