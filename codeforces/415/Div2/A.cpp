#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int marks[n];
    int curr_marks = 0;
    for (int i=0; i<n; ++i) {
        scanf("%d", &marks[i]);
        curr_marks += marks[i];
    }
    int avg = trunc(round((float)curr_marks/(float)n));
    int extra = 0;
    while (avg < k) {
        ++extra;
        curr_marks += k;
        avg = trunc(round(((float)curr_marks)/((float)n + extra)));
    }
    printf("%d\n", extra);
    return 0;
}
