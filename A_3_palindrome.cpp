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
	cin >> n;

	if (n == 1)
	{
		cout << "a" << endl;
		return;
	}
	if (n == 2)
	{
		cout << "ab" << endl;
		return;
	}

	string ans = "ab";

	for (int i = 2; i < n; ++i)
	{
		string s = ans.substr(i - 2);
		if (s == "aa" || s == "ab")
			ans += "b";
		else if (s == "bb" || s == "ba")
			ans += "a";
	}

	cout << ans << endl;
}

int main()
{
	cout << "WHAT THE FoensuhoenuheouUCK " << endl;
	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();
}