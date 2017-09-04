#include <bits/stdc++.h>
using namespace std;

int main(void){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    string c;
    cin >> c;
    
    int count[26];
    fill(count, count + 26, 0);

    for(int i = 0; i < n; ++i) {
        ++count[c[i] - 97];
    }
    
    bool flag = true;
    for (int i = 0; i < 26; ++i) {
        if (k < count[i]) {
            flag = false;
            break;
        }
    }

    if (flag)
        cout << "Yes\n";
    else 
        cout << "No\n";

    return 0;
}
