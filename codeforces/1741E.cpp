// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int _ = 0; _ < T; _++) {
		int N;
		cin >> N;
		vector<int> seq(N);
		vector<bool> dp(N);
		for (int i = 0; i < N; i++) {
			int inp;
			cin >> inp;
			seq[i] = inp;
		}

		for (int i = 0; i < N; i++) {
			if (i == 0 && seq[0] < N){
				dp[seq[0]] = true;
			} 
			if (i > 0 && dp[i-1] == true && i + seq[i] < N)
			{
				dp[i + seq[i]] = true;
			}
			if ((i - seq[i] - 1 >= 0 && dp[i - seq[i] - 1] == true) || seq[i] == i)
			{
				dp[i] = true;
			}
		}

		if (dp[N-1]) cout << "YES\n";
		else cout << "NO\n";
	}
}