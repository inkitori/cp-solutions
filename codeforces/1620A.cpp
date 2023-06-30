// Source: https://usaco.guide/general/io

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		string s;
		cin >> s;

		int cnt = 0;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == 'N') cnt++;
		}

		if (cnt == 1) cout << "NO\n";
		else cout << "YES\n";
	}
}