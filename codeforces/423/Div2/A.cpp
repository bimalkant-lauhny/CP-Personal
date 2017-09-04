#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, one_seater, two_seater;
    cin >> n >> one_seater >> two_seater;
    
    int group;
    int half_seats = 0;
    int denied = 0; 
    for (int i=0; i<n; ++i) {
        cin >> group;
        if (group == 1) {
            if (one_seater > 0)
                --one_seater;
            else if (two_seater > 0) {
                ++half_seats;
                --two_seater;
            } else if (half_seats > 0)
                --half_seats;
            else
                ++denied;
        } else {
            if (two_seater > 0)
                --two_seater;
            else
                denied += 2;
        }
    }

    cout << denied << endl;
    return 0;
}
