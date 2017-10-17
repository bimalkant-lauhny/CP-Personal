#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    double n, a; 
    cin >> n >> a;

    double dec = 180.0/n;
    double ina = (n - 2.0) * dec;
    double curdiff = 180, prediff = curdiff, cura = ina; 
    int minv = n;
    for (int i=3; i<=n; ++i) {
        curdiff = abs(a - cura);
        if (curdiff > prediff) {
            minv = i - 1;
            break;
        }
        prediff = curdiff;
        cura -= dec;
    }

    cout << 1 << " " << 2 << " " << minv << "\n";
    return 0;
}
