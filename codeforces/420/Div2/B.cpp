#include <bits/stdc++.h>
using namespace std;

long long series_sum(long long l) {
    return (l * (l+1)) / 2;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    long long m, b;
    cin >> m >> b;
    long long bananas = 0;
    for (long long y=0; y<=b; ++y) {
        long long x = m * (b - y);
        bananas = max(bananas, (x+1)*series_sum(y) + (y+1)*series_sum(x));
    }

    cout << bananas << "\n";
    return 0;
}
