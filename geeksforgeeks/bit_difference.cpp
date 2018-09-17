#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        int x = a ^ b, setcnt = 0;
        while(x) {
            x = x & (x-1);
            ++setcnt;
        }
        cout << setcnt << endl;
    }
    return 0;
}
