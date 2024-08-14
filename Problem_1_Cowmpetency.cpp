#include <bits/stdc++.h>

using namespace std;

// #define int long long // lol

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
	int N, Q, C;
	cin >> N >> Q >> C;

	vector<int> a(N);
	vector<pair<int, int>> pairs(Q);
	unordered_map<int, int> hToA;

	for (int &i : a)
		cin >> i;

	for (auto &p : pairs)
	{
		cin >> p.first >> p.second;
		--p.first;
		--p.second;
		hToA[p.second] = max(hToA[p.second], p.first);
	}

	vector<int> runningMax(N);

	if (!a[0])
		a[0] = 1;

	runningMax[0] = a[0];

	for (int i = 1; i < a.size(); ++i)
	{
		if (hToA.find(i) == hToA.end())
		{
			if (!a[i])
				a[i] = 1;
		}
		else
		{
			int prevMax = runningMax[hToA[i]];
			if (prevMax + 1 > C)
			{
				cout << "-1\n";
				return;
			}
			a[i] = prevMax + 1;
		}

		runningMax[i] = max(a[i], runningMax[i - 1]);
	}

	for (int i : a)
		cout << i << " ";
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