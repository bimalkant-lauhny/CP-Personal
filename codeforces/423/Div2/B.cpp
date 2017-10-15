#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    string sheet[n];
    for (int i=0; i<n; ++i)
        cin >> sheet[i];

    int bcnt = 0, maxX = -1, minX = 101, maxY = -1, minY = 101;
    
    for (int x=0; x<n; ++x) {
        for (int y=0; y<m; ++y) {
            if (sheet[x][y] == 'B') {
                ++bcnt;
                if (maxX < x)
                    maxX = x;

                if (minX > x)
                    minX = x;

                if (maxY < y) 
                    maxY = y;

                if (minY > y)
                    minY = y;
            }
        }
    }
    
    int len = 1; 
    if (bcnt != 0) {
        len = max(maxX - minX + 1, maxY - minY + 1);
    }

    if (len > n || len > m)
        cout << -1 << "\n";
    else
        cout << (len*len) - bcnt << "\n";

    return 0;
}
