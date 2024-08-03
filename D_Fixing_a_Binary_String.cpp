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
	string s;

	cin >> n >> k >> s;
	char lastChar = s.back();
	int endCount = 0;
	bool foundBreak = false;
	for (int i = s.size() - 1; i >= 0; --i)
	{
		if (s[i] == lastChar)
			++endCount;
		else
		{
			foundBreak = true;
			break;
		}
	}

	if (!foundBreak)
	{
		if (endCount == k)
			cout << "1\n";
		else
			cout << "-1\n";
		return;
	}
	if (endCount > k)
	{
		cout << "-1\n";
		return;
	}
	if (endCount == k)
	{
		char recentChar = s.front();
		int currentCount = 0;
		for (int i = 0; i < s.size() - endCount; ++i)
		{
			char c = s[i];
			if (c != recentChar)
			{
				if (currentCount != k)
				{
					cout << "-1\n";
					return;
				}
				recentChar = c;
				currentCount = 0;
			}

			++currentCount;
		}
		if (currentCount != k)
		{
			cout << "-1\n";
			return;
		}
		cout << k << '\n';
		return;
	}

	bool passedFirst = false;
	char recentChar = s.front();
	int currentCount = 0;
	int search = k - endCount;
	int ans = -1;

	for (int i = 0; i < s.size() - endCount; ++i)
	{
		char c = s[i];
		if (c != recentChar)
		{
			if (!passedFirst)
			{
				if (currentCount != search)
				{
					cout << "-1\n";
					return;
				}
				ans = i - 1;
				passedFirst = true;
				recentChar = c;
				currentCount = 1;
			}
			else
			{
				if (currentCount == k)
					continue;
				if (currentCount < k)
				{
					cout << "-1\n";
					return;
				}
				if (ans != -1)
				{
					cout << "-1\n";
					return;
				}
				if (currentCount != search + k)
				{
					cout << "-1\n";
					return;
				}
				ans = i - (currentCount - search + 1);
				recentChar = c;
				currentCount = 1;
			}
		}
		else
			currentCount++;
	}

	if (!passedFirst)
	{
		if (currentCount != search)
		{
			cout << "-1\n";
			return;
		}
		ans = s.size() - 1;
	}
	else
	{
		if (currentCount == k)
		{
		}
		if (currentCount < k)
		{
			cout << "-1\n";
			return;
		}
		if (ans != -1)
		{
			cout << "-1\n";
			return;
		}
		if (currentCount != search + k)
		{
			cout << "-1\n";
			return;
		}
		ans = s.size() - (currentCount - search + 1);
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