#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int wi = 0;
    int total_pebbles = 0;
    for (int i=0; i<n; ++i){
        scanf("%d", &wi);
        total_pebbles += ceil((float)wi/k);
    }
    int res = ceil(total_pebbles/2.0);
    printf("%d\n", res);
    return 0;
}
