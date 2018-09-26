#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        string s;
        cin >> s;
        int l = -1, ls = 0;
        int p = 0;
        for (char &c: s) {
            if (c == '(') {
                if (l == k) ls += p;
                ++l;
                p = 0;
            } else if (c == ')') {
                if (l == k) ls += p;
                --l;
                p = 0;
            } else if (l == k){
                p = p*10 + (c-'0');
            } else {
                p = 0;
            }
        }
        cout << ls << endl;
    }
    return 0;
}
