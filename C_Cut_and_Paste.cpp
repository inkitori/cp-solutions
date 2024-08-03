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
	ll x;
	string s;
	cin >> x >> s;
	ll ans = s.size();

	for (ll i = 0; i < x; ++i)
	{
		ll mul = s[i] - '1';
		ll delta = ans - (i + 1);

		if (s.size() < x)
		{
			string deltaStr = s.substr(i + 1);
			for (int j = 0; j < mul; ++j)
				s += deltaStr;
		}

		ans = (ans + delta * mul) % mod;
	}

	cout << (ans % mod + mod) % mod << '\n';
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