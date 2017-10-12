#include <bits/stdc++.h>
using namespace std;
#define newl "\n"

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    string gsts;
    cin >> gsts;
    
    int fpos[26];
    for (int i=0; i<n; ++i) {
        fpos[gsts[i] - 'A'] = i;
    }

    bool active[26];
    fill(active, active+26, false);
    bool res = false;
    for (int i=0; i<n; ++i) {
        active[gsts[i] - 'A'] = true;

        int nact = 0;
        for (int j=0; j<26; ++j) {
            if (active[j])
                ++nact;
        }
        if (nact > k) {
            res = true;
            break;
        }

        if (fpos[gsts[i] - 'A'] == i)
            active[gsts[i] - 'A'] = false;
    }

    if (res)
        cout << "YES" << newl;
    else
        cout << "NO" << newl;
    return 0;
}
