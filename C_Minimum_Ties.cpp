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
	int n;
	cin >> n;
	if (n % 2 == 1)
	{
		for (int i = 0; i < n - 1; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				if (i + j == n)
					break;
				if (j > (n - 1) / 2)
					cout << "-1 ";
				else
					cout << "1 ";
			}
		}
	}
	else
	{
		for (int i = 0; i < n - 1; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				if (i + j == n)
					break;
				if (j == n / 2)
					cout << "0 ";
				else if (j > n / 2)
					cout << "-1 ";
				else
					cout << "1 ";
			}
		}
	}
	cout << '\n';
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