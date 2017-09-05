#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int c, v0, v1, a, l;
    cin >> c >> v0 >> v1 >> a >> l;
    
    c -= min(v0, v1); 
    int days = 1;
    int cur_a = a;
    while (c > 0) {
        c += l;
        c -= min(v0 + cur_a, v1); 
        cur_a += a;
        ++days;
    }

    cout << days << endl;

    return 0;
}
