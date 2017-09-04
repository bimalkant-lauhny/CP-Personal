#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    char u, v;
    cin >> u >> v;

    int n;
    cin >> n;

    n %= 4;

    char cwpos[4] = {'^', '>', 'v', '<'};
    char ccwpos[4] = {'^', '<', 'v', '>'};
    
    string res = "undefined";
    for (int i=0; i<4; ++i) {
        int newpos = (i+n) % 4; 
        if (u == cwpos[i] &&
                cwpos[newpos] == v) {
            if (res == "ccw")
                res = "undefined";
            else
                res = "cw";
        } 
        if (u == ccwpos[i] &&
                ccwpos[newpos] == v) {
            if (res == "cw")
                res = "undefined";
            else
                res = "ccw";
        }
    }

    cout << res << "\n";
    return 0;
}
