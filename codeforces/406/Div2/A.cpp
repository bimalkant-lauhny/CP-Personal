#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d;
    scanf("%d %d", &a, &b);
    scanf("%d %d", &c, &d);

    int n = max(a,max(b, max(c, d)));
    int res = -1;
    int j;
    for (int i=0; i<=n; ++i){
       j = (b + i*a - d) / c;
       if ((b + i*a) == (d + j*c) && j >= 0){
           res = j;
           break;
       }
    }

    if (res > -1)
        printf("%d\n", d + res*c);
    else
        printf("-1\n");
       
    return 0;
}
