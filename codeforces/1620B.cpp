// Source: https://usaco.guide/general/io

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
	long long T;
	
	cin >> T;
	
	for (long long i = 0; i < T; i++) {
		long long ans = 0;
		long long w, h;
		cin >> w >> h;

		for (long long j = 0; j < 2; j++) {
			long long K; 
			cin >> K;

			long long min = INT_MAX;
			long long max = INT_MIN;

			for (long long k = 0; k < K; k++) {
				long long tmp;
				cin >> tmp;

				if (tmp > max) max = tmp;
				if (tmp < min) min = tmp;
			}

			long long area = (max - min) * h;
			if (area > ans) ans = area;
		}

		for (long long j = 0; j < 2; j++) {
			long long K; 
			cin >> K;

			long long min = INT_MAX;
			long long max = INT_MIN;

			for (long long k = 0; k < K; k++) {
				long long tmp;
				cin >> tmp;

				if (tmp > max) max = tmp;
				if (tmp < min) min = tmp;
			}

			long long area = (max - min) * w;
			if (area > ans) ans = area;
		}

		cout << ans << '\n';
	}
}