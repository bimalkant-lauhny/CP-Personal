#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    int a[10001];
    for (int i=1; i<=n; ++i)
        cin >> a[i];

    int l, r, p, s;
    while(m--) {
        cin >> l >> r >> p;
        s = 0; 
        for (int j=l; j<=r; ++j) {
            if (a[j]<a[p])
                ++s;
        }
        if (l+s != p)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}
