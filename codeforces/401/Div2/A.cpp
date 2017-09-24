#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int shuffle[6][3] = {
        {0, 1, 2},
        {1, 0, 2},
        {1, 2, 0},
        {2, 1, 0},
        {2, 0, 1},
        {0, 2, 1},
    };
    
    int n;
    cin >> n;
    n %= 6;

    int pos;
    cin >> pos;

    cout << shuffle[n][pos] << endl;
    return 0;
}
