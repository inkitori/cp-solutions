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
	ll n;
	ll m;
	cin >> n >> m;

	vector<pair<ll, ll>> flowers(n);

	for (auto &pair : flowers)
		cin >> pair.first;

	for (auto &pair : flowers)
		cin >> pair.second;

	sort(flowers.begin(), flowers.end(), [&](auto &a, auto &b)
		 { return a.first < b.first; });

	ll ans = 0;

	// for (auto &[petalCount, quantity] : flowers)
	// {
	// 	cout << "( " << petalCount << ", " << quantity << " ), ";
	// }
	// cout << '\n';

	for (int i = 0; i < flowers.size(); ++i)
	{
		if (i == flowers.size() - 1 || flowers[i + 1].first - flowers[i].first > 1)
		{
			ans = max(ans, min(m / flowers[i].first, flowers[i].second) * flowers[i].first);
			continue;
		}

		auto mul1 = min(m / flowers[i].first, flowers[i].second);
		auto diff = m - flowers[i].first * mul1;
		auto mul2 = min(diff / flowers[i + 1].first, flowers[i + 1].second);

		auto val = flowers[i].first * mul1 + flowers[i + 1].first * mul2;
		auto diff2 = m - val;

		ans = max(ans, val + min(diff2, min(mul1, flowers[i + 1].second - mul2)));
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