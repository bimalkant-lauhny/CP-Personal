#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long l, r, x, y, k;
    cin >> l >> r >> x >> y >> k;

    bool flag = false;

    for (long long i=x; i<=y; ++i) {
        long long temp = i * k;
        if (temp >= l && temp <= r) {
            flag = true;
            break;
        }
    }

    if (flag == false) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }
    return 0;
}
