#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    
    int l, r;
    int max_nl = INT_MIN, min_nr = INT_MAX;
    for (int i=0; i<n; ++i) {
        cin >> l >> r;
        if (r < min_nr)
            min_nr = r;
        if (l > max_nl)
            max_nl = l;
    }
    
    int m;
    cin >> m;
    int max_ml = INT_MIN, min_mr = INT_MAX;
    for (int i=0; i<m; ++i) {
        cin >> l >> r;
        if (r < min_mr)
            min_mr = r;
        if (l > max_ml)
            max_ml = l;
    }
    
    int res = max(max_nl - min_mr, max_ml - min_nr);
    if (res <= 0)
        cout << 0 << endl;
    else
        cout << res << endl;
    return 0;
}
