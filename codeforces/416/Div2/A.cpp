#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int a_steps = sqrt(a);
    int b_steps = sqrt(b);
    if (b_steps*(b_steps+1) > b)
        --b_steps;
    if (a_steps <= b_steps)
        printf("Vladik\n");
    else
        printf("Valera\n");
    return 0;
}
