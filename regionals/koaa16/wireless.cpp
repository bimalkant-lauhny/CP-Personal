#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for (int i=1; i<=t; i++) {
        double n;
        cin >> n;

        if (n < 33) {
            cout << "Case " << i << ": " 
                 << (long long)((long long)1 << (long long)n) - 1 << "\n"; 
        } else {
            cout << "Case " << i << ": 8589934591\n" ; 
        }
    }
    return 0;
}
