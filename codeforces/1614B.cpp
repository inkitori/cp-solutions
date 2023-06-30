// Source: https://usaco.guide/general/io

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	long long T;
	cin >> T;

	for (long long i = 0; i < T; i++) {
		long long N;
		cin >> N;

		vector<long long> vi(N);
		vector<long long> indices(N);

		for (long long j = 0; j < N; j++) {
			cin >> vi[j];
		}

		for (long long j = 0; j < N; j++) {
			indices[j] = j;
		}

		sort(indices.rbegin(),indices.rend(), [&](long long i,long long j){return vi[i]<vi[j];} );

		long long ans = 0;
		long long pos = 1;
		vector<long long> viAns(N + 1);

		viAns[0] = 0;

		for (long long j = 0; j < N; j++) {
			viAns[indices[j] + 1] = pos;

			ans += 2 * abs(pos) * vi[indices[j]];
			if (pos < 0) {
				pos = -pos;
				pos++;
			}
			else pos = -pos;
		}

		cout << ans << '\n';

		for (long long j = 0; j < N + 1; j++) {
			cout << viAns[j] << " ";
		}

		cout << '\n';
	}
}