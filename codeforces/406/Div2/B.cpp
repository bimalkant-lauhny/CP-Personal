#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    int n, m;
    cin >> n >> m;
    int k, j;
    bool flag, traitors = false;
    unordered_map <int, bool> mp;

    while (m--) {
        cin >> k;
        flag = false;
        while (k--) {
            cin >> j;
            mp[j] = true;
            if (mp[j] && mp[-j])
                flag = true;
        }
        if (!flag)
            traitors = true;
        mp.clear();
    }

    if (traitors)
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;

    return 0;
}
