#include <bits/stdc++.h>
using namespace std;
int drops[11][51];
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        for (int i=0; i<=n; ++i) {
            for (int j=0; j<=k; ++j) {
                if (i==0 || j==0) {
                    drops[i][j] = 0;
                } else if (j == 1) {
                    drops[i][j] = 1;
                } else if (i == 1) {
                    drops[i][j] = j;
                } else {
                    drops[i][j] = INT_MAX;
                    for (int x=1; x<=j; ++x) {
                        int curDrops = 1 + max(drops[i-1][x-1], drops[i][j-x]);
                        if (curDrops < drops[i][j])
                            drops[i][j] = curDrops;
                    }
                }
            }
        }
        cout << drops[n][k] << endl;
    }
    return 0;
}
