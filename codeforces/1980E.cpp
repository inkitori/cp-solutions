// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

bool checkVecEquality(vector<int> &a, vector<int> &b)
{
	for (int i = 0; i < a.size(); i++) if (a[i] != b[i]) return false;
	return true;
}

bool validateMatrix(vector<vector<int>> &A, vector<vector<int>> &B)
{
	for (int i = 0; i < A.size(); i++)
	{
		sort(A[i].begin(), A[i].end());
		sort(B[i].begin(), B[i].end());
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	// cout << "PRINTING A: " << '\n';
	// for (auto &vec : A)
	// {
	// 	for (int i : vec) cout << i << " ";
	// 	cout << '\n';
	// }

	// cout << "PRINTING B: " << '\n';
	// for (auto &vec : B)
	// {
	// 	for (int i : vec) cout << i << " ";
	// 	cout << '\n';
	// }

	for (int i = 0; i < A.size(); i++) for (int j = 0; j < A[0].size(); j++) if (A[i][j] != B[i][j]) return false;

	return true;
}

void solve(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &AColBased, vector<vector<int>> &BColBased)
{
	if (!validateMatrix(A, B)) 
	{
		cout << "NO\n";
		return;
	}

	if (!validateMatrix(AColBased, BColBased)) 
	{
		cout << "NO\n";
		return;
	}

	cout << "YES\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int N, M;
		cin >> N >> M;

		vector<vector<int>> A(N, vector<int>(M, 0));
		vector<vector<int>> B(N, vector<int>(M, 0));

		vector<vector<int>> AColBased(M, vector<int>(N, 0));
		vector<vector<int>> BColBased(M, vector<int>(N, 0));

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				int val;
				cin >> val;
				A[i][j] = val;
				AColBased[j][i] = val;
			}
		}
	
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				int val;
				cin >> val;
				B[i][j] = val;
				BColBased[j][i] = val;
			}
		}


		solve(A, B, AColBased, BColBased);
	}
}