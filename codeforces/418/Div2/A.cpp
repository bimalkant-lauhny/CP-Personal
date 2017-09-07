#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, k;
    cin >> n >> k;

    int a[n];
    int b[k];

    for(int i=0; i<n; ++i)
        cin >> a[i];

    for(int i=0; i<k; ++i)
        cin >> b[i];

    if (k > 1)
        cout << "Yes" << endl;
    else {
        int pos = 0;
        while(a[pos] != 0)
            ++pos;

        a[pos] = b[0];

        pos = 1;
        while(pos < n && a[pos-1] < a[pos])
            ++pos;

        if (pos == n)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}
