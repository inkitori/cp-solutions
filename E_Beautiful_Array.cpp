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

constexpr int maxN = 100005;
vector<int> prefix(maxN), suffix(maxN);
void solve()
{
	int n, k;
	map<int, vector<int>> m;

	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		m[x % k].push_back(x);
	}

	int ans = 0;

	int oddCount = 0;

	for (auto &[mod, vec] : m)
	{
		if (vec.size() % 2 != 0)
		{
			if (oddCount)
			{
				cout << "-1" << '\n';
				return;
			}
			++oddCount;
		}

		sort(vec.begin(), vec.end());

		if (vec.size() % 2 == 0)
		{
			for (int i = 0; i < vec.size() - 1; ++i)
			{
				if (i % 2 == 1)
					continue;
				ans += (vec[i + 1] - vec[i]) / k;
			}
		}
		else
		{
			int val = INT_MAX;
			for (int i = 1; i < vec.size(); i += 2)
			{
				prefix[i] = (vec[i] - vec[i - 1]) / k;
				if (i > 1)
					prefix[i] += prefix[i - 2];
			}
			for (int i = vec.size() - 2; i >= 0; i -= 2)
			{
				suffix[i] = (vec[i + 1] - vec[i]) / k;
				if (i < vec.size() - 2)
					suffix[i] += suffix[i + 2];
			}

			for (int i = 0; i < vec.size(); ++i)
			{
				int tmp = 0;
				if (i % 2 == 0)
				{
					if (i - 1 > 0)
						tmp += prefix[i - 1];
					if (i + 1 < vec.size())
						tmp += suffix[i + 1];
				}
				else
				{
					tmp += (vec[i + 1] - vec[i]) / k;
					if (i - 2 > 0)
						tmp += prefix[i - 2];
					if (i + 2 < vec.size())
						tmp += suffix[i + 2];
				}
				val = min(val, tmp);
			}
			ans += val;
		}
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