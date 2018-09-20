#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int res = ((n & 0x0F) << 4) | ((n & 0xF0) >> 4);
        cout << res << endl;
    }
    return 0;
}
