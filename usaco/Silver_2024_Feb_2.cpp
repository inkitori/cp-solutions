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

inline void process(string &s, stack<char> &vec)
{
	char lastChar = '0';
	for (char c : s)
	{
		if (c != lastChar)
		{
			vec.push(c);
			lastChar = c;
		}
	}
}

inline queue<string> generateMoves(stack<char> b1, stack<char> b2, char base1, char base2)
{
	queue<string> moves;
	stack<char> b3;

	bool b1Valid = false;
	bool b2Valid = false;

	while (!b1Valid || !b2Valid)
	{
		if (b1.empty() || (b1.size() == 1 && b1.top() == base1))
		{
			b1Valid = true;
		}

		if (b2.empty() || (b2.size() == 1 && b2.top() == base2))
		{
			b2Valid = true;
		}

		if (b1Valid && b2Valid)
			break;

		else if (b1Valid)
		{
			char b2Val = b2.top();

			if (b2Val == base1)
				moves.push("2 1");
			else
				moves.push("2 3");

			if (b2Val == base2)
			{
				if (b3.empty() || b3.top() != b2Val)
					b3.push(b2Val);
			}

			b2.pop();
		}

		else if (b2Valid)
		{
			char b1Val = b1.top();

			if (b1Val == base1)
				moves.push("1 3");
			else
				moves.push("1 2");

			if (b1Val == base1)
			{
				if (b3.empty() || b3.top() != b1Val)
					b3.push(b1Val);
			}

			b1.pop();
		}
		else
		{
			if (b1.top() != b2.top())
			{
				if (b1.size() < b2.size())
				{
					if (b3.empty() || b3.top() != b1.top())
						b3.push(b1.top());

					b1.pop();

					moves.push("1 3");
				}
				else
				{
					if (b3.empty() || b3.top() != b2.top())
						b3.push(b2.top());

					b2.pop();

					moves.push("2 3");
				}
			}
			else
			{
				if (b1.top() == base2)
				{
					b2.pop();
					moves.push("2 1");
				}
				else
				{
					b1.pop();
					moves.push("1 2");
				}
			}
		}
	}

	while (!b3.empty())
	{
		if (b3.top() == base1)
			moves.push("3 1");
		else
			moves.push("3 2");

		b3.pop();
	}

	return moves;
}

void solve()
{
	int N, P;
	string s1, s2;
	cin >> N >> P >> s1 >> s2;

	stack<char> b1, b2;
	process(s1, b1);
	process(s2, b2);

	queue<string> movesA = generateMoves(b1, b2, '1', '2');
	queue<string> movesB = generateMoves(b1, b2, '2', '1');

	queue<string> minMoves = movesA;
	if (movesA.size() < movesB.size())
		minMoves = movesA;
	else
		minMoves = movesB;

	cout << minMoves.size() << '\n';
	if (P == 2 || P == 3)
	{
		while (!minMoves.empty())
		{
			cout << minMoves.front() << '\n';
			minMoves.pop();
		}
	}
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