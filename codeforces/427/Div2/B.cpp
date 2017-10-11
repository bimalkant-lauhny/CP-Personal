#include <bits/stdc++.h>
using namespace std;
#define newl "\n"

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int k;
    cin >> k;

    string n;
    cin >> n;

    int cnt[10] = {};
    for (int i=0; i<n.size(); ++i) {
        ++cnt[n[i] - '0'];
    }
    
    int summ = 0;
    for (int i=0; i<10; ++i) 
        summ += (i*cnt[i]);

    int diff = k - summ;

    if (diff <= 0)
        cout << 0 << newl;
    else {
        int dig = 0, x;
        for (int i=0; i<10; ++i) {
            x = min(diff/(9-i), cnt[i]);
            diff -= (x*(9-i));
            dig += x;
            cnt[i] -= x;
            if (cnt[i] && diff) {
                ++dig;
                break;
            }
            if (!diff)
                break;
        }
        cout << dig << newl;
    }
    return 0;
}
