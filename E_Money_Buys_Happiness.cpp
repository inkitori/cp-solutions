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

int dp(vector<int> &cost, vector<int> &happiness, int month, int salary, int money, vector<vector<int>> &tableCompute)
{
	if (month == cost.size())
		return 0;

	if (tableCompute[month][money] != -1)
		return tableCompute[month][money];

	int val = dp(cost, happiness, month + 1, salary, money + salary, tableCompute);
	if (money >= cost[month])
		val = max(val, happiness[month] + dp(cost, happiness, month + 1, salary, money - cost[month] + salary, tableCompute));

	tableCompute[month][money] = val;

	return val;
}
void solve()
{
	vector<vector<int>> tableCompute(51, vector<int>(5100000000, -1));

	int m, x;
	cin >> m >> x;
	vector<int> cost(m), happiness(m);
	for (int i = 0; i < m; ++i)
		cin >> cost[i] >> happiness[i];

	cout << dp(cost, happiness, 0, x, 0, tableCompute) << '\n';
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