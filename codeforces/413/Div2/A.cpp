#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t, k ,d;
    scanf("%d %d %d %d", &n, &t, &k, &d);

    // find cakes remaining at time d
    
    int rem = n - k * (d/t + 1);
    if (rem > 0)
        printf("YES\n");
    else 
        printf("NO\n");

    return 0;
}
