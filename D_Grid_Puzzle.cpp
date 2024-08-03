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
	vector<int> a(n);
	vector<bool> left(n, false), right(n, false), skip(n, false);
	for (int &i : a)
		cin >> i;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] == 0)
			skip[i] = true;
		if (a[i] == 1 || a[i] == 2)
			left[i] = true;
		if (a[i] == 3 || a[i] == 4)
		{
			left[i] = true;
			right[i] = true;
		}
	}
	int ans = 0;
	for (int i = a.size() - 1; i >= 0; --i)
	{
		if (skip[i])
			continue;
		if (i == 0)
		{
			++ans;
			continue;
		}
		if (a[i] > 4 || (left[i] && right[i]))
		{
			++ans;
			continue;
		}
		if (left[i] && left[i - 1] && !right[i - 1])
		{
			++ans;
			skip[i - 1] = true;
			continue;
		}
		if (right[i] && right[i - 1] && !left[i - 1])
		{
			++ans;
			skip[i - 1] = true;
			continue;
		}
		if (left[i])
		{
			++ans;
			left[i - 1] = false;
			continue;
		}
		if (right[i])
		{
			++ans;
			right[i - 1] = false;
			continue;
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