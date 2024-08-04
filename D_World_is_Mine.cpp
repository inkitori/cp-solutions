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

void process(vector<pair<int, int>> &cakes, int n)
{
	vector<int> count(n, 0);
	for (int i = 0; i < n; ++i)
	{
		int tastiness;
		cin >> tastiness;
		++count[tastiness - 1];
	}

	for (int tastiness = 0; tastiness < count.size(); ++tastiness)
		if (count[tastiness] > 0)
			cakes.push_back({tastiness, count[tastiness]});

	sort(cakes.begin(), cakes.end(), [&](auto &a, auto &b)
		 { return a.first < b.first; });
}
void solve()
{
	int n;
	cin >> n;
	vector<pair<int, int>> cakes;
	process(cakes, n);
	vector<int> dp(cakes.size(), 0);
	dp.back() = 1;

	for (int i = dp.size() - 2; i >= 0; --i)
	{
		for (int j = i + 1; j < dp.size(); ++j)
		{
			if (cakes[j].second > 1)
				dp[i] = max(dp[i], dp[j] + 1);
			else
				dp[i] = max(dp[i], dp[j]);
		}
	}

	cout << *max_element(dp.begin(), dp.end()) << '\n';
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