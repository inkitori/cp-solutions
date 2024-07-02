// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

void solve()
{
	long long N, M;
	cin >> N >> M;

	vector<long long> programmingSkills(N + M + 1);
	vector<long long> testingSkills(N + M + 1);
	vector<int> assignedRole(N + M + 1);

	for (auto &x : programmingSkills)
		cin >> x;
	for (auto &x : testingSkills)
		cin >> x;

	long long totalSkill = 0;

	int badIndex = -1;
	int preferredRole = -1;

	for (int i = 0; i < programmingSkills.size(); i++)
	{
		if (N && M)
		{
			if (programmingSkills[i] > testingSkills[i])
			{
				assignedRole[i] = 0;
				totalSkill += programmingSkills[i];
				N--;
			}
			else
			{
				assignedRole[i] = 1;
				totalSkill += testingSkills[i];
				M--;
			}
		}
		else if (N)
		{
			if (testingSkills[i] > programmingSkills[i] && badIndex == -1)
			{
				preferredRole = 1;
				badIndex = i;
			}

			assignedRole[i] = 0;
			totalSkill += programmingSkills[i];
			N--;
		}
		else if (M)
		{
			if (programmingSkills[i] > testingSkills[i] && badIndex == -1)
			{
				preferredRole = 0;
				badIndex = i;
			}

			assignedRole[i] = 1;
			totalSkill += testingSkills[i];
			M--;
		}
	}

	vector<long long> ans(programmingSkills.size(), totalSkill);

	for (int i = 0; i < ans.size(); i++)
	{

		if (i < badIndex && assignedRole[i] == preferredRole)
		{
			if (preferredRole == 0)
				ans[i] += (-programmingSkills[i] + programmingSkills[badIndex] - testingSkills[badIndex] + testingSkills.back());
			if (preferredRole == 1)
				ans[i] += (-testingSkills[i] + testingSkills[badIndex] - programmingSkills[badIndex] + programmingSkills.back());

			continue;
		}

		if (assignedRole[i] == 0)
			ans[i] += programmingSkills.back() - programmingSkills[i];
		else
			ans[i] += testingSkills.back() - testingSkills[i];
	}

	for (auto &i : ans)
		cout << i << ' ';
	cout << '\n';
}

int main()
{
	int T;
	cin >> T;

	for (int _ = 0; _ < T; _++)
		solve();
}