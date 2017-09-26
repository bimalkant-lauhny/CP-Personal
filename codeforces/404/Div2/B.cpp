#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

double pos[60001], spd[60001];

bool meet(int n, double t) {
    double rng[60001][2]; 

    double L = rng[0][0] = pos[0] - spd[0]*t;
    double R = rng[0][1] = pos[0] + spd[0]*t;
    for (int i=1; i<n; ++i) {
        rng[i][0] = pos[i] - spd[i]*t;
        if (rng[i][0] > L)
            L = rng[i][0];

        rng[i][1] = pos[i] + spd[i]*t;
        if (rng[i][1] < R)
            R = rng[i][1];
    }

    return (L <= R);
} 

int main(void) {
    
    int n;
    scanf("%d", &n);

    for (int i=0; i<n; ++i)
        scanf("%lf", &pos[i]);

    for (int i=0; i<n; ++i)
        scanf("%lf", &spd[i]);
   
    double max_t = 1e9, min_t = 0;
    // binary search 
    double mid;
    while(min_t < max_t){
        mid = (max_t + min_t)/2.0;
        if (meet(n, mid))
            max_t = mid - 0.000001;
        else
            min_t = mid + 0.000001; 
    }
    printf("%lf\n",max_t);
    return 0;
}
