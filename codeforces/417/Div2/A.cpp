#include <bits/stdc++.h>
using namespace std;

int lights[4][4];

bool check_hit(int i) {

    int left = (i-1);
    if (left < 0)
        left += 4; 
    if (lights[i][0])
        if (lights[i][3] || lights[left][3] == 1)
            return true;

    int straight = (i + 2) % 4;
    if (lights[i][1])
        if (lights[i][3] || lights[straight][3] == 1)
            return true;

    int right = (i+1) % 4; 
    if (lights[i][2])
        if (lights[i][3] || lights[right][3] == 1)
            return true;

    return false;
}

int main() {
    for (int i=0; i<4; ++i) 
        for (int j=0; j<4; ++j)
            scanf("%d", &lights[i][j]);
    
    bool hit = false;
    for (int i=0; i<4; ++i){
        hit = check_hit(i);            
        if (hit)
            break;
    }

    if (hit)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
