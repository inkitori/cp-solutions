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
	vector<pair<int, int>> movies(n);

	for (auto &movie : movies)
		cin >> movie.first;

	for (auto &movie : movies)
		cin >> movie.second;

	int movie1 = 0;
	int movie2 = 0;

	int ones = 0;
	int negs = 0;

	for (const auto &[a, b] : movies)
	{
		if (a == 1 && b == 1)
			++ones;
		if (a == -1 && b == -1)
			++negs;
		if (a == 1 && b == 0)
			++movie1;
		if (a == 0 && b == 1)
			++movie2;
		if (a == 1 && b == -1)
			++movie1;
		if (a == -1 && b == 1)
			++movie2;
	}

	for (int i = 0; i < ones; ++i)
	{
		if (movie1 < movie2)
			++movie1;
		else
			++movie2;
	}
	for (int i = 0; i < negs; ++i)
	{
		if (movie1 < movie2)
			--movie2;
		else
			--movie1;
	}

	cout << min(movie1, movie2) << '\n';
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