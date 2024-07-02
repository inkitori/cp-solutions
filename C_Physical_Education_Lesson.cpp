#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vll = vector<long long>;
using ll = long long;
#define MOD 10e9 + 7

void printStuff(int k, int d)
{
	int curr = 1;
	bool goingUp = true;
	for (int i = 0; i < d; i++)
	{
		cout << curr << '\t';
		if (curr == k)
		{
			goingUp = false;
			curr--;
		}
		else if (curr == 1)
		{
			goingUp = true;
			curr++;
		}
		else
			curr += goingUp ? 1 : -1;
	}
	cout << endl;
}
void solve()
{
	int n;
	cin >> n;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 2; i <= 111; i++)
		printStuff(i, 111);
	// int t;
	// cin >> t;
	// while (t--)
	// 	solve();
}