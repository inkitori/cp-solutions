#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vll = vector<long long>;
using ll = long long;
#define MOD 10e9 + 7

ll minCost(vi &river, ll distance)
{
	vll dp(river.size());
	deque<ll> dq;

	ll l = 0;
	ll r = 1;

	dq.push_front(1);
	dp[0] = 1;

	while (r < river.size())
	{
		dp[r] = river[r] + 1;
		dp[r] += dq.front();

		while (!dq.empty() && dp[r] < dq.back())
			dq.pop_back();
		dq.push_back(dp[r]);

		if (r - l - 1 < distance)
			r++;
		else
		{
			if (dp[l] == dq.front())
				dq.pop_front();
			r++;
			l++;
		}
	}

	return dp.back();
}

void solve()
{
	ll n, m, k, d;
	cin >> n >> m >> k >> d;

	vll costs;
	for (ll i = 0; i < n; i++)
	{
		vi river(m);
		for (auto &x : river)
			cin >> x;

		costs.push_back(minCost(river, d));
	}

	ll ans = 0;

	int l = 0;
	int r = 0;
	ll currentCost = 0;

	while (r - l + 1 <= k)
	{
		currentCost += costs[r];
		r++;
	}

	ans = currentCost;

	r--;

	while (r < costs.size())
	{
		r++;
		if (r == costs.size())
			break;
		currentCost += costs[r];
		currentCost -= costs[l];
		l++;

		ans = min(ans, currentCost);
	}

	cout << ans << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll t;
	cin >> t;
	while (t--)
		solve();
}