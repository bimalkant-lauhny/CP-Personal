#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

bool hole[1000001] = {};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m, k;
    cin >> n >> m >> k;

    int t;
    while(m--) {
        cin >> t;
        hole[t] = true;
    }
    
    int u, v, bonepos = 1;
    while (k--) {
        cin >> u >> v;
        if (hole[bonepos] == true)
            continue;
        if (u == bonepos)
            bonepos = v;
        else if (v == bonepos)
            bonepos = u;
    }

    cout << bonepos << endl;

    return 0;
}
