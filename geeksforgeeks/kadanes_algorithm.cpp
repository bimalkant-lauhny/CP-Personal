#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i=0; i<n; ++i)
            cin >> arr[i];

        int maxSoFar = arr[0], curMax = arr[0];
        for (int i=1; i<n; ++i) {
            curMax = max(arr[i], curMax+arr[i]);
            maxSoFar = max(maxSoFar, curMax);
        }

        cout << maxSoFar << endl;
    }
    return 0;
}
