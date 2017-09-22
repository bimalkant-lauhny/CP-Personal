#include <bits/stdc++.h>
using namespace std;

int main() {
    int l, b;
    scanf("%d %d", &l, &b);
    int years = 0;
    while (l <= b){
        l = 3*l;
        b = 2*b;
        ++years;
    }
    printf("%d\n", years);
    return 0;
}
