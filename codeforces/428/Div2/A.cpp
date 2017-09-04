#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, k;
    cin >> n >> k;

    int candies_given = 0, 
        min_days = 0, 
        candies = 0,
        candy = 0;

    for (int i=0; i<n; ++i) {
        cin >> candy;
        candies += candy;

        if (k > 0) {
            if (candies > 8) {
                k -= 8; 
                candies -= 8;
            } else {
                k -= candies;
                candies = 0;
            }
            ++min_days;
        }
    }
    
    if (k > 0) {
        min_days = -1;
    }

    cout << min_days << endl;

    return 0;
}
