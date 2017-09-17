#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int prices[n];
    int min_dist = INT_MAX;
    for (int i=0; i<n; ++i) {
        cin >> prices[i];
        if (prices[i] != 0 && prices[i] <= k)
            min_dist = min(min_dist, (abs(i+1 - m))*10);

    }
    cout << min_dist << endl;
    return 0;
}
