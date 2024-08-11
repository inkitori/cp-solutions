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

string solve()
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(m);
	for (auto &i : a)
		cin >> i;

	if (n % k != 0)
	{
		int segs = (n / k) + 1;
		int thresh = n % k;
		int count = 0;

		for (auto &i : a)
		{
			if (i > segs)
				return "NO";
			if (i == segs)
				++count;
			if (count > thresh)
				return "NO";
		}
		return "YES";
	}

	int segs = n / k;
	for (auto &i : a)
		if (i > segs)
			return "NO";
	return "YES";
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