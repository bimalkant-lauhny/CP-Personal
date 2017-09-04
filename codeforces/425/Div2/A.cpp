#include <bits/stdc++.h>
using namespace std; 
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n, k;
    cin >> n >> k;

    long long res = n / k;

    if (res & (long long)1)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
