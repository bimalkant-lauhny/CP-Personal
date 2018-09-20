#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i=0; i<n; ++i) {
            cin >> arr[i];
        }
        sort(arr, arr+n);
        bool found = false;
        for (int i=0; i<n-2; ++i) {
            int l=i+1, r=n-1;
            while(l<r) {
                int cursum = arr[i] + arr[l] + arr[r];
                if (cursum == x) {
                    found = true;
                    break;
                } else if (cursum < x) {
                    ++l;
                } else {
                    --r;
                }
            }
            if (found)
                break;
        }
        cout << found << endl;
    }
    return 0;
}
