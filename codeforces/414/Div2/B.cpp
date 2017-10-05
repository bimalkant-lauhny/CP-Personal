#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

#define ERR 0.000001

int main(void) {

    double n, h;
    scanf("%lf %lf", &n, &h);
    
    double i = 1.00000000;
    while (i < n) {
        double res =  h * sqrt(i/n);
        printf("%lf ", res);
        i += 1.00000000;
    }
    printf("\n");
    return 0;
}
