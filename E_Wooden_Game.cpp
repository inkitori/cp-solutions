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

void solve()
{
	int k;
	cin >> k;
	vector<int> trees(k);
	for (int i = 0; i < k; ++i)
	{
		cin >> trees[i];
		int trash;
		for (int j = 0; j < trees[i] - 1; ++j)
			cin >> trash;
	}

	sort(trees.begin(), trees.end(), greater<>());
	int mask = trees[0];
	if (trees.size() == 1)
	{
		cout << mask << '\n';
		return;
	}

	int ans = mask;
	for (int i = trees[1]; i >= 0; --i)
	{
		ans = max(ans, mask | i);
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