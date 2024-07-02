#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vll = vector<long long>;
using ll = long long;

void solve()
{
	int n;
	cin >> n;

	vector<string> operationsList;
	string permutation = "";
	int permutationsSum = (n * (n + 1)) / 2;

	int sum = 0;
	int operations = 0;

	for (int i = 1; i <= n; i++)
		permutation += " " + to_string(i);

	for (int i = 1; i <= n; i++)
	{
		operationsList.push_back("1 " + to_string(i) + permutation + '\n');
		sum += permutationsSum;
		operations++;
	}

	for (int i = 1; i <= n && permutationsSum > i * n; i++)
	{
		operationsList.push_back("2 " + to_string(i) + permutation + '\n');
		sum = sum - (i * n) + permutationsSum;
		operations++;
	}

	cout << sum << " " << operations << '\n';
	for (auto &x : operationsList)
		cout << x;
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