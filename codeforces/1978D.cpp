#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
	ll N, C;
	cin >> N >> C;

	vector<ll> candidates(N);

	for (ll &x : candidates)
	{
		cin >> x;
	}

	candidates[0] += C;

	vector<ll> ans(N, 0);

	vector<ll> prefixSum(N, 0);
	vector<ll> suffixMax(N, 0);
	vector<ll> prefixMax(N, 0);

	prefixSum[0] = candidates[0];
	for (ll i = 1; i < candidates.size(); i++) prefixSum[i] = candidates[i] + prefixSum[i-1];
	
	suffixMax[N-1] = candidates.back();
	for (ll i = N-2; i >= 0; i--) suffixMax[i] = max(candidates[i], suffixMax[i+1]);

	prefixMax[0] = candidates[0];
	for (ll i = 1; i < N; i++) prefixMax[i] = max(candidates[i], prefixMax[i-1]);

	if (prefixMax.back() == candidates[0]) ans[0] = 0;
	else ans[0] = 1;

	for (ll i = 1; i < N; i++)
	{
		if (prefixMax.back() == candidates[i]) 
		{
			if (prefixMax[i-1] == candidates[i]) ans[i] = i; 
			else ans[i] = 0;
			continue;
		}

		if (prefixSum[i-1] + candidates[i] >= suffixMax[i]) ans[i] = i;
		else ans[i] = i+1;
	}

	for (ll i : ans) cout << i << " ";
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for (int _; _ < T; _++) solve();
}