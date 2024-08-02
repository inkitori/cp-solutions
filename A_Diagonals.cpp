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
	int n, k;
	cin >> n >> k;

	int ans = 0;
	if (k == 0)
	{
		cout << 0 << '\n';
		return;
	}
	if (n >= k)
	{
		cout << 1 << '\n';
		return;
	}

	ans++;
	k -= n;

	for (int i = n - 1; i >= 1; --i)
	{
		if (i >= k)
		{
			ans++;
			break;
		}
		ans++;
		k -= i;
		if (i >= k)
		{
			ans++;
			break;
		}
		ans++;
		k -= i;
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