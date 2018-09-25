#include <bits/stdc++.h>
using namespace std;

int binomialCoeff(int n, int k) {
    int res = 1;
    if (k > n-k) k = n-k;
    for (int i=0; i<k; ++i) {
        res *= (n-i);
        res /= (i+1);
    }
    return res;
}

int getNthCatalan(int n) {
    return binomialCoeff(2*n, n)/(n+1);
}

int catalan[12];
int fillCatalan() {
    // Nth Catalan DP
    int n = 11;
    catalan[0] = catalan[1] = 1;
    for (int i=2; i<=n; ++i) {
        catalan[i] = 0;
        for (int j=0; j<i; ++j) {
            catalan[i] += (catalan[j] * catalan[i-j-1]);
        }
    }
}

int main() {
	int t;
	cin >> t;
	//fillCatalan();
	while(t--) {
	    int n;
	    cin >> n;
        // cout << catalan[n] << endl;
	    cout << getNthCatalan(n) << endl;
	}
	return 0;
}
