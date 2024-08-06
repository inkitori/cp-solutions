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

struct Disk
{
	ll x;
	ll y;
	ll r;
};

constexpr double epsilon = 0.00001;
inline double dist(ll x1, ll y1, ll x2, ll y2)
{
	return sqrt(pow((double)x2 - (double)x1, 2) + pow((double)y2 - (double)y1, 2));
}
inline bool fuzzyEqual(double x, double y)
{
	return abs(x - y) < epsilon;
}

void color(int i, int c, vector<bool> &visited, vector<vector<int>> &colors, vector<vector<int>> &adj)
{
	if (visited[i])
		return;

	visited[i] = true;
	colors[c].push_back(i);

	for (int j = 0; j < adj[i].size(); ++j)
		color(adj[i][j], c, visited, colors, adj);
}

bool check(int source, vector<vector<int>> &adj, int flip, vector<int> &nodeState)
{
	if (nodeState[source] != 0)
		return nodeState[source] == flip;

	nodeState[source] = flip;

	for (int node : adj[source])
	{
		if (!check(node, adj, flip == 1 ? -1 : 1, nodeState))
		{
			return false;
		}
	}

	return true;
}

void solve()
{
	int n;
	cin >> n;
	vector<Disk> disks(n);
	vector<vector<int>> adj(n);
	vector<vector<int>> colors(n);

	for (auto &d : disks)
		cin >> d.x >> d.y >> d.r;

	for (int i = 0; i < disks.size(); ++i)
	{
		for (int j = 0; j < disks.size(); ++j)
		{
			if (i == j)
				continue;
			if (fuzzyEqual(disks[i].r + disks[j].r, dist(disks[i].x, disks[i].y, disks[j].x, disks[j].y)))
				adj[i].push_back(j);
		}
	}

	int curColor = 0;
	vector<bool> visited(n, false);

	for (int i = 0; i < disks.size(); ++i)
	{
		if (visited[i])
			continue;

		color(i, curColor, visited, colors, adj);
		++curColor;
	}

	for (int i = 0; i < curColor; ++i)
	{
		auto color = colors[i];
		vector<int> nodeState(n, 0);
		auto c = check(color[0], adj, 1, nodeState);

		if (c)
		{
			vector<int> count(3);
			for (int i : nodeState)
				count[i + 1]++;
			if (count[0] != count[2])
			{
				cout << "YES\n";
				return;
			}
		}
		else
		{
			cout << "NO\n";
			return;
		}
	}

	cout << "NO\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();
}