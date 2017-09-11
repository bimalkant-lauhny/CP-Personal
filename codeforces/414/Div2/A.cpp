#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int n;
    scanf("%d", &n);

    int xi, notes = 0;
    for (int i=0; i<n; ++i) {
        scanf("%d", &xi);
        if (xi > b && xi < c)
            ++notes;
    }
    printf("%d", notes);
    return 0;
}
