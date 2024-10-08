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
	ll m;
	cin >> n >> m;

	vector<ll> petals(n);

	for (auto &i : petals)
		cin >> i;

	sort(petals.begin(), petals.end());

	ll ans = 0;

	queue<ll> q;
	ll currentCount = 0;

	for (auto &petal : petals)
	{
		while ((!q.empty() && petal - q.front() >= 2) || petal + currentCount > m)
		{
			currentCount -= q.front();
			q.pop();
		}

		q.push(petal);
		currentCount += petal;

		if (currentCount <= m)
			ans = max(currentCount, ans);
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