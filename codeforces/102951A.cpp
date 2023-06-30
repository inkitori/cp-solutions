#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    int x[5000], y[5000];

    for (int i = 0; i < n; ++i) cin >> x[i];
    for (int i = 0; i < n; ++i) cin >> y[i];

    int maxDist = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int dx = abs(x[i] - x[j]);
            int dy = abs(y[i] - y[j]);


            maxDist = max(maxDist, (dx * dx) + (dy * dy));
        }
    }

    cout << maxDist << '\n';
    
}