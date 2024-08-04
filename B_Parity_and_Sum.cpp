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

bool checkParity(vector<int> &nums, int parity)
{
	for (auto &i : nums)
		if (i % 2 != parity)
			return false;

	return true;
}

void solve()
{
	int n;
	cin >> n;
	vector<int> nums(n);

	for (auto &i : nums)
		cin >> i;

	sort(nums.begin(), nums.end());

	if (checkParity(nums, 0) || checkParity(nums, 1))
	{
		cout << "0" << '\n';
		return;
	}

	int ans = 0;
	for (auto &i : nums)
		if (i % 2 == 0)
			++ans;

	if (nums.back() % 2 == 0)
	{
		ll biggestOdd = 0;
		ll biggestEven = nums.back();
		priority_queue<int, vector<int>, greater<int>> pq;

		// for (int i : nums)
		// 	cout << i << ", ";
		// cout << '\n';
		for (int i = nums.size() - 1; i >= 0; --i)
		{
			if (nums[i] % 2 == 1)
			{
				biggestOdd = nums[i];
				break;
			}
		}

		for (int i = 0; i < nums.size() - 1; ++i)
			if (nums[i] % 2 == 0)
				pq.push(nums[i]);

		// cout << "PQ SIZE: " << pq.size() << '\n';
		// cout << "BIGGEST ODD: " << biggestOdd << '\n';
		// cout << "BIGGEST EVEN: " << biggestEven << '\n';

		while (!pq.empty() && biggestOdd < biggestEven)
		{
			if (pq.top() > biggestOdd)
				break;

			biggestOdd += pq.top();
			// cout << "BIGGEST ODD: " << biggestOdd << '\n';
			pq.pop();
		}

		if (biggestOdd < biggestEven)
			++ans;
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
}