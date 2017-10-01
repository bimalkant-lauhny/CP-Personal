#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string x, y;
    cin >> x;
    cin >> y;

    string z;

    for (int i=0; i<x.size(); ++i) {
        if (y[i] > x[i]) {
            z = "-1";
            break;
        } else {
            z.push_back(y[i]);
        }
    }

    cout << z << endl;
    return 0;
}
