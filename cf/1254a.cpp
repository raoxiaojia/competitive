#include "bits/stdc++.h"

using namespace std;

int main() {
	int t;
	int r, c, n;
	cin >> t;
	while (t) {
		t--;
	cin >> r >> c >> n;
	vector<string> farm;
	vector<string> ans;
	int riceCount = 0;
	for (int i = 0; i < r; i++) {
		string str;
		cin >> str;
		farm.push_back(str);
		for (int j = 0; j < str.length(); j++) {
			if (str[j] == 'R') riceCount++;
		}
		str = "";
		for (int j = 0; j < c; j++) {
			str += '.';
		}
		ans.push_back(str);
	}
	bool rightwards = true;
	int i = 0;
	int j = 0;
	string chickName = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
	for (int k = 0; k < n; k++) {
		int curRice = 0;
		int avgRice = riceCount / (n - k);
		while (curRice < avgRice) {
			ans[i][j] = chickName[k];
			if (farm[i][j] == 'R') {
				curRice++;
			}
			if (rightwards) {
					j++;
					if (j == c) {
						j = c - 1;
						i++;
						rightwards = false;
					}
				}
				else {
					j--;
					if (j == -1) {
						j = 0;
						i++;
						rightwards = true;
					}
				}
		}
		riceCount -= avgRice;
	}
	while ((i<r) || ((i == r-1) && (((j<c) && rightwards) || ((j>=0) && !rightwards)))) {
		ans[i][j] = chickName[n-1];
				if (rightwards) {
					j++;
					if (j == c) {
						j = c - 1;
						i++;
						rightwards = false;
					}
				}
				else {
					j--;
					if (j == -1) {
						j = 0;
						i++;
						rightwards = true;
					}
				}
	}
	for (int i = 0; i < r; i++) {
		cout << ans[i] << endl;
	}
}
	return 0;
}