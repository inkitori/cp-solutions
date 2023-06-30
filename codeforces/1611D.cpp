// Source: https://usaco.guide/general/io

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int T_idx = 0; T_idx < T; T_idx++) {
		bool INVALID = false;

		int N;
		cin >> N;

		vector<int> bi(N);
		vector<int> pi(N);
		vector<int> dist(N, -1);
		vector<int> w(N, -1);

		for (int i = 0; i < N; i++) cin >> bi[i];
		for (int i = 0; i < N; i++) cin >> pi[i];

		// if (bi[pi[0] - 1] != pi[0]) {
		// 	cout << -1 << '\n';
		// 	continue;
		// }

		dist[pi[0] - 1] = 0;
		w[pi[0] - 1] = 0;

		int curDist = 0;
		for (int i = 0; i < N; i++) {
			int ancDist = dist[bi[pi[i] - 1] - 1];

			if (ancDist == -1) {
				cout << -1;
				INVALID = true;
				break;
			}
			int edgeLength = curDist - ancDist;

			w[pi[i] - 1] = edgeLength;
			dist[pi[i] - 1] = curDist;

			curDist++;
		}

		if (!INVALID) {
			for (int i = 0; i < N; i++) cout << w[i] << ' ';
		}
		
		cout << '\n';


	}
}