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
	int n, p, s;
	cin >> n >> p >> s;
	vector<int> a(n);
	--p;
	--s;

	for (int i = s; i <= p; ++i)
		a[i] = 1;

	for (int i = s - 1; i >= 0; --i)
		a[i] = a[i + 1] == 1 ? -1 : 1;
	for (int i = p + 1; i < n; ++i)
		a[i] = a[i - 1] == 1 ? -1 : 1;

	for (int i : a)
		cout << i << ' ';
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