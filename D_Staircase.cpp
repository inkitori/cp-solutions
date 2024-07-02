// #include "allImports.h"
#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vll = vector<long long>;
using ll = long long;

ll computeCost(vll &steps)
{
	if (steps.size() == 0)
		return 0;

	ll cost = 0;

	if (steps.size() % 2 == 0)
	{
		for (ll &x : steps)
			cost += 2 * x;

		return cost;
	}

	ll maxCost = 0;
	int indexMax = -1;

	for (int i = 0; i < steps.size(); i++)
	{
		if (i % 2 == 0 && steps[i] >= maxCost)
		{
			maxCost = steps[i];
			indexMax = i;
		}
	}

	// cout << "INDEX_MAX: " << indexMax << " MAX: " << maxCost << '\n';

	for (int i = 0; i < steps.size(); i++)
	{
		if (i == indexMax)
		{
			cost += steps[indexMax];
			continue;
		}
		cost += 2 * steps[i];
	}

	return cost;
}

void solve()
{
	int n;
	cin >> n;

	ll ans = 0;
	vll steps(n);

	for (auto &x : steps)
		cin >> x;

	vll block;

	for (int i = 0; i < steps.size(); i++)
	{
		if (steps[i] == 0)
		{
			ans += computeCost(block);
			block.clear();
		}
		else
			block.push_back(steps[i]);
	}

	ans += computeCost(block);
	cout << ans << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();
}