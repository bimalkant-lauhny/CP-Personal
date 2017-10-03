#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int p, x, y;
    cin >> p >> x >> y;

    bool flag = false;
    int tempx = x, i;
    while(tempx >= y) {
        i = (tempx / 50) % 475;
        for (int j=0; j<25; ++j){
            i = (i * 96 + 42) % 475;
            if (i + 26 == p) {
                flag = true;
                break;
            }
        }
        if (flag)
            break;
        tempx -= 50;
    }
    
    if (flag) {
        cout << 0 << endl;
        return 0;
    }
    
    tempx = x + 50;
    while (tempx < y)
        tempx += 50;

    flag = false;
    while (true) {
        i = (tempx / 50) % 475;
        for (int j=0; j<25; ++j){
            i = (i * 96 + 42) % 475;
            if (i + 26 == p) {
                flag = true;
                break;
            }
        }
        if (flag)
            break;
        tempx += 50;
    }

    cout << (tempx - x + 50) / 100 << endl;
    return 0;
}
