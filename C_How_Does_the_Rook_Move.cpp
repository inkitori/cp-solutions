#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vll = vector<long long>;
using ll = long long;
#define MOD 1000000007;

ll factorial(const ll n)
{
	ll f = 1;
	for (int i = 1; i <= n; ++i)
	{
		f *= i;
		f %= MOD;
	}
	return f;
}

void solve()
{
	int n, k;
	cin >> n >> k;

	int reduction = n;

	for (int i = 0; i < k; i++)
	{
		int r, c;
		cin >> r >> c;
		if (r == c)
			reduction -= 1;
		else
			reduction -= 2;
	}

	vll dp(reduction + 1);
	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i < dp.size(); i++)
	{
		dp[i] = 2 * (i - 1) * dp[i - 2] + dp[i - 1];
		dp[i] %= MOD;
	}

	cout << dp.back() << '\n';
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