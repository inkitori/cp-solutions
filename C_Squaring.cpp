#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vll = vector<long long>;
using ll = long long;
#define MOD 10e9 + 7

#define benchmark(code)                                                               \
	{                                                                                 \
		auto t1 = std::chrono::high_resolution_clock::now();                          \
		{                                                                             \
			code                                                                      \
		}                                                                             \
		auto t2 = std::chrono::high_resolution_clock::now();                          \
		auto ms_int = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1); \
		std::chrono::duration<double, std::milli> ms_double = t2 - t1;                \
		std::cerr << "Elapsed time: " << ms_int.count() << "ms\n";                    \
		std::cerr << "Elapsed time (double): " << ms_double.count() << "ms\n";        \
	}

void solve()
{
	int n;
	cin >> n;
	vector<ll> a(n);
	vector<ll> dp(n, 0);
	for (auto &i : a)
		cin >> i;

	ll ans = 0;

	for (int i = 1; i < a.size(); ++i)
	{
		if (a[i] == 1 && a[i - 1] > 1)
		{
			cout << "-1" << '\n';
			return;
		}
		else if (a[i] == 1)
			continue;
		else if (a[i - 1] == 1)
			continue;

		ll cp = a[i];

		if (a[i] > a[i - 1])
		{
			ll cp2 = a[i - 1];
			ll diff = 0;
			while (cp2 < cp)
			{
				cp2 = pow(cp2, 2);
				diff++;
			}
			if (cp < cp2)
				dp[i]++;
			if (diff > dp[i - 1])
				dp[i] = 0;
			else
			{
				dp[i] += dp[i - 1] - diff;
			}
		}
		else
		{
			while (cp < a[i - 1])
			{
				cp = pow(cp, 2);
				dp[i]++;
			}
			dp[i] += dp[i - 1];
		}
		ans += dp[i];
	}

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