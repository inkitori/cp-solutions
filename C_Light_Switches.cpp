#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vll = vector<long long>;
using ll = long long;
constexpr ll mod = 1'000'000'007;

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

int convert(int i, int k)
{
	if (i % (2 * k) == 0)
		return 2 * k;
	return i % (2 * k);
}

void solve()
{
	int n, k;
	cin >> n >> k;
	vector<int> chips(n);
	for (ll &chip : chips)
		cin >> chip;

	sort(chips.begin(), chips.end());
	int l = convert(chips[0], k);
	int r = convert(chips[0] + k - 1, k);

	int ans = chips[0];
	for (int i = 1; i < chips.size(); ++i)
	{
		if (l < r)
		{
			l = max(l, chips[i]);
		}
	}
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