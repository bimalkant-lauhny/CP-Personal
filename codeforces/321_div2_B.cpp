#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
#define x first
#define y second

pll mf[100001];

bool comp(pll p1, pll p2) {
    return p1.x < p2.x;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; ll d;
    cin >> n >> d;
    
    mf[0].x = 0;
    mf[0].y = 0;
    for (int i=1; i<=n; ++i) {
        cin >> mf[i].x >> mf[i].y;
    }

    sort(mf, mf+n+1, comp);
    
    for (int i=1; i<=n; ++i) {
        mf[i].y += mf[i-1].y;
    }
/*    
    for (int i=1; i<=n; ++i) {
        cout << "(" << mf[i].x << ", " << mf[i].y << ") ";   
    }
    cout << endl;
*/
    int lo=1, hi=1;
    ll maxf = mf[1].y;

    while (hi <= n) {
        if (mf[hi].x - mf[lo].x < d) {
            maxf = max(maxf, mf[hi].y - mf[lo-1].y);
            ++hi;
        } else {
            ++lo;
        }
//        cout << hi << " " << lo << endl;
    }

    cout << maxf << "\n";
    return 0;
}
