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

ll numDigits(ll n)
{
	ll nDigits = 0;

	while (n > 0)
	{
		n /= 10;
		++nDigits;
	}
	return nDigits;
}

ll calc(ll n, ll a, ll b)
{
	// guaranteed to fit in 32 bit
	auto digits = numDigits(n) * a - b;

	while (numDigits(n) < digits)
		n = n * pow(10, numDigits(n)) + n;
	while (numDigits(n) > digits)
		n /= 10;

	return n;
}

void solve()
{
	ll n;
	cin >> n;
	vector<pair<ll, ll>> ans;

	ll nDigits = numDigits(n);

	for (ll a = 1; a <= 10000; ++a)
	{
		ll val = n * a;
		ll valDigits = numDigits(val);

		for (ll digCount = valDigits; digCount >= 1; --digCount)
		{
			ll b = nDigits * a - digCount;
			if (b <= 0)
				continue;
			ll reg = val - b;
			if (calc(n, a, b) == reg)
				ans.push_back({a, b});
		}
	}
	cout << ans.size() << '\n';
	for (auto &[a, b] : ans)
		cout << a << " " << b << '\n';
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