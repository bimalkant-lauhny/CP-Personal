#include <bits/stdc++.h>
using namespace std;
int arr[10000001], lmin[10000001], rmax[10000001];
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for (int i=0; i<n; ++i) {
            cin >> arr[i];
        }
        lmin[0] = arr[0];
        for (int i=1; i<n; ++i) {
            lmin[i] = min(lmin[i-1], arr[i]);
        }

        rmax[n-1] = arr[n-1];
        for (int j=n-2; j>=0; --j) {
            rmax[j] = max(rmax[j+1], arr[j]);
        }

        int i=0, j=0, maxdiff = 0;
        while(i < n && j < n) {
            if (lmin[i] <= rmax[j]) {
                maxdiff = max(maxdiff, j-i);
                ++j;
            } else {
                ++i;
            }
        }
        cout << maxdiff << endl;
    }
    return 0;
}
