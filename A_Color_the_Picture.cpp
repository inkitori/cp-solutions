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

bool test(int r, int c, vector<int> &a)
{
	bool moreThanTwo = false;
	int colsPopulated = 0;

	for (int i : a)
	{
		int cols = i / r;
		if (colsPopulated + cols > c)
		{
			if (colsPopulated == c - 1)
			{
				if (moreThanTwo && cols >= 2)
					return true;
				else
					return false;
			}
			else
				return true;
		}
		if (cols > 2)
			moreThanTwo = true;

		if (cols > 1)
			colsPopulated += cols;

		if (colsPopulated == c)
			return true;
	}
	return false;
}

void solve()
{
	int r, c, k;
	cin >> r >> c >> k;
	vector<int> a(k);
	for (auto &i : a)
		cin >> i;

	sort(a.rbegin(), a.rend());

	if (test(r, c, a) || test(c, r, a))
		cout << "Yes\n";
	else
		cout << "No\n";
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