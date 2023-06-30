// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int N;
		cin >> N;
		if (N%2==0) cout << N/2;
		else cout << (N-1)/2;
		cout << '\n';
	}
}