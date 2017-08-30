#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    for(int i=1; i<=t; ++i) {

        int A[10001], B[10001];

        int n;
        cin >> n;

        for (int j=0; j<n; ++j) {
            cin >> B[j]; 
            A[j] = B[j] & 32767;
            B[j] = B[j] >> 16;
        }

        cout << "Case " << i << ":\n";

        for (int j=0; j<n; ++j) {
            cout << A[j] << " ";
        }
        cout << "\n";

        for (int j=0; j<n; ++j) {
            cout << B[j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
