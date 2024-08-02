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
	ll N, K, S;

	cin >> N >> K >> S;

	ll distanceWalked = 0;
	queue<ll> houses;
	bool atLeft = true;

	for (int i = 0; i < K; ++i)
	{
		if (distanceWalked == S)
			break;

		if (distanceWalked + (N - 1) <= S)
		{
			if (atLeft)
				houses.push(N);
			else
				houses.push(1);

			distanceWalked += N - 1;
			atLeft = !atLeft;
		}
		else
		{
			ll diff = S - distanceWalked;
			if (atLeft)
				houses.push(diff + 1);
			else
				houses.push(N - diff);

			distanceWalked = S;
		}
	}

	if (distanceWalked == S)
	{
		cout << "YES\n";
		while (!houses.empty())
		{
			cout << houses.front() << " ";
			houses.pop();
		}
	}
	else
		cout << "NO\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();
}