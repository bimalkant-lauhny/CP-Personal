#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int r, d;
    cin >> r >> d;

    int n;
    cin >> n;

    int req_pts = 0;
    
    double in_r = r - d;
    double xi, yi, ri;
    while (n--) {
        cin >> xi >> yi >> ri;
        double c_d = sqrt(xi*xi + yi*yi);
        if (in_r <= c_d - ri &&
            r >= c_d + ri) {
            ++req_pts;
        }
    }
    cout << req_pts << endl;
    return 0;
}
