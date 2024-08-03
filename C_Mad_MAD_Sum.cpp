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
	ll sum = 0;
	cin >> n;

	vector<ll> a(n);
	for (auto &i : a)
		cin >> i;
	for (auto &i : a)
		sum += i;

	ll cur = 0;
	unordered_map<ll, ll> count;
	for (auto &i : a)
	{
		++count[i];
		if (count[i] >= 2 && i > cur)
			cur = i;
		i = cur;
	}

	for (auto &i : a)
		sum += i;

	ll cur2 = 0;
	unordered_map<ll, ll> count2;
	for (auto &i : a)
	{
		++count2[i];
		if (count2[i] >= 2 && i > cur2)
			cur2 = i;
		i = cur2;
	}

	// for (auto &i : a)
	// 	cout << i << ", ";
	// cout << '\n';
	// cout << sum << '\n';
	ll mul = 1;
	for (int i = a.size() - 1; i >= 0; --i)
	{
		sum += a[i] * mul;
		++mul;
	}
	cout << sum << '\n';
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