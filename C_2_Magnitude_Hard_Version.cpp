#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vll = vector<long long>;
using ll = long long;
constexpr ll mod = 998244353;

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
	vector<int> arr(n);
	for (int &i : arr)
		cin >> i;

	ll ans = 1;
	ll cur = 0;
	for (int i = 0; i < arr.size(); ++i)
	{
		if (arr[i] >= 0)
		{
			ans = (ans * 2) % mod;
			cur += arr[i];
			continue;
		}

		if (i == arr.size() - 1 || arr[i + 1] > 0)

			cur += arr[i];
	}
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