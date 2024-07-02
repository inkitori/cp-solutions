#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vll = vector<long long>;
using ll = long long;
#define MOD 10e9 + 7;

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

char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void solve()
{
	int n;
	cin >> n;
	string s;
	cin >> s;

	ll columnCount = 0;
	for (int i = 0; i < s.size(); i++)
		columnCount += s[i] - '0';

	ll totalCount = 0;

	string ans = "";
	int subAmount = 0;
	for (int i = s.size() - 1; i >= 0; i--)
	{
		columnCount -= subAmount;

		totalCount /= 10;

		totalCount += columnCount;

		ans += digits[totalCount % 10];

		subAmount = s[i] - '0';
	}

	ans += to_string(totalCount / 10);

	reverse(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++)
	{
		if (ans[i] != '0')
		{
			ans = ans.substr(i);
			break;
		}
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

		return 0;
}