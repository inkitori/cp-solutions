#include <bits/stdc++.h>

using namespace std;

// #define int long long // lol

using vi = vector<int>;
using vll = vector<long long>;
using ll = long long;
using vpi = vector<pair<int, int>>;
using vpll = vector<pair<ll, ll>>;
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

inline bool checkAllZero(vpll &b)
{
	for (auto &p : b)
		if (p.second)
			return false;
	return true;
}

inline ll calcScore(vpll &a)
{
	return a[(a.size() / 2) - 1].first + a.back().first;
}

inline ll lastOne(vpll &a)
{
	for (int i = a.size() - 1; i >= 0; --i)
		if (a[i].second)
			return i;

	return 0;
}

ll solve()
{
	ll n, k;
	cin >> n >> k;
	vpll a(n);

	for (auto &p : a)
		cin >> p.first;
	for (auto &p : a)
		cin >> p.second;

	sort(a.begin(), a.end());

	if (checkAllZero(a))
		return calcScore(a);

	ll ans = 0;

	{
		// testing bubble
		vpll aBub = a;
		aBub[lastOne(aBub)].first += k;
		sort(aBub.begin(), aBub.end());
		ans = max(ans, calcScore(aBub));
	}

	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
		cout << solve() << '\n';
}