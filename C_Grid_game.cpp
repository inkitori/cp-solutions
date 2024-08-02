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
	string s;
	cin >> s;

	bool verticalState = s[0] == '0' ? true : false;
	if (verticalState)
		cout << "1 1" << '\n';
	else
		cout << "4 3" << '\n';

	int pointer = 1;
	while (pointer < s.size())
	{
		if (pointer == s.size() - 1)
		{
			cout << "1 3" << '\n';
			return;
		}

		if (verticalState)
		{
			if (s[pointer] == '0' && s[pointer + 1] == '0')
			{
				cout << "3 1" << '\n';
				cout << "1 1" << '\n';
				pointer += 2;
			}
			else if (s[pointer] == '0' && s[pointer + 1] == '1')
			{
				cout << "3 1" << '\n';
				cout << "4 3" << '\n';
				pointer += 2;

				verticalState = false;
			}
			else if (s[pointer] == '1' && s[pointer + 1] == '0')
			{
				cout << "4 3" << '\n';
				cout << "3 1" << '\n';
				pointer += 2;

				verticalState = false;
			}
			else if (s[pointer] == '1' && s[pointer + 1] == '1')
			{
				cout << "4 1" << '\n';
				cout << "4 3" << '\n';
				pointer += 2;
			}
		}
		else
		{
			if (s[pointer] == '0' && s[pointer + 1] == '0')
			{
				cout << "3 1" << '\n';
				cout << "1 1" << '\n';
				pointer += 2;
			}
			else if (s[pointer] == '0' && s[pointer + 1] == '1')
			{
				cout << "1 1" << '\n';
				cout << "4 1" << '\n';
				pointer += 2;

				verticalState = true;
			}
			else if (s[pointer] == '1' && s[pointer + 1] == '0')
			{
				cout << "4 1" << '\n';
				cout << "1 1" << '\n';
				pointer += 2;

				verticalState = true;
			}
			else if (s[pointer] == '1' && s[pointer + 1] == '1')
			{
				cout << "4 1" << '\n';
				cout << "4 3" << '\n';
				pointer += 2;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	// int t;
	// cin >> t;
	// while (t--)
	solve();
}