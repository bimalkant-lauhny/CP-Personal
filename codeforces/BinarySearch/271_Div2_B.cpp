#include <bits/stdc++.h>
using namespace std;

int pilesum[100001] = {};

int binary_search(int n, int t) {
    int lo=1, hi=n, mid;
    int res = -1; 
    while(lo <= hi) {
        mid = (lo+hi)/2;
        if (pilesum[mid] >= t && pilesum[mid-1] < t) {
            res = mid; 
            break;
        }
        if (pilesum[mid] > t) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return res;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    
    int pile;
    for (int i=1; i<=n; ++i) {
        cin >> pile;
        pilesum[i] = pilesum[i-1] + pile;
    }
    
    int q, t;
    cin >> q;
    while (q--) {
        cin >> t;
        cout << binary_search(n, t) << "\n";
    }
    return 0;
}
