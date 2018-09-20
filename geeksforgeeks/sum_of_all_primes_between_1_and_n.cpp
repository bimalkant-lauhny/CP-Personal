#include <bits/stdc++.h>
using namespace std;
# define LIM 1000001
int isPrime[LIM];
int main() {
    isPrime[0] = isPrime[1] = 0;
    memset(isPrime+2, -1, LIM*sizeof(int));
    for (int i=2; i<LIM; ++i) {
        if(isPrime[i] == -1) {
            isPrime[i] = 1;
            for (int j=i+i; j<LIM; j += i) {
                isPrime[j] = 0;
            }
        }
    }
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        long long res = 0;
        for (int i=0; i<=n; ++i) {
            if (isPrime[i])
                res += (long long)i;
        }
        cout << res << endl;
    }
    return 0;
}
