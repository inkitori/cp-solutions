#include <bits/stdc++.h>
using namespace std;

double height(int x, int r)
{
	return sqrt((double)r * r - (double)x * x);
}

void solve()
{
	int R;
	cin >> R;
	int ans = 0;

	for (int i = 0; i <= R; i++)
	{
		for (int j = ceil(height(i, R)); j <= floor(height(i, R + 1)) && j < ceil(height(i, R + 1)); j++)
			ans++;
	}

	ans -= 2;
	ans *= 4;
	ans += 4;

	cout << ans << '\n';
}

int main()
{
	int T;
	cin >> T;
	for (int _ = 0; _ < T; _++)
		solve();
}