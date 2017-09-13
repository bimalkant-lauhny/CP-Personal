#include <bits/stdc++.h>
using namespace std;

#define RATED 0
#define UNRATED 1
#define MAYBE 2

int main() {
    int n, a, b;
    scanf("%d", &n);
    
    int status = MAYBE; 
    n--;
    scanf("%d %d", &a, &b);
    int temp_a, temp_b;
    while (n--) {
        if (a != b) {
            status = RATED;
        }
        scanf("%d %d", &temp_a, &temp_b);
        if (a < temp_a && status == MAYBE) {
            status = UNRATED;
        }
        a = temp_a;
        b = temp_b;
    }

    if (a != b) {
        status = RATED;
    }

    
    if (status == UNRATED)
        printf("unrated\n");
    else if (status == RATED)
        printf("rated\n");
    else 
        printf("maybe\n");

    return 0;
}
