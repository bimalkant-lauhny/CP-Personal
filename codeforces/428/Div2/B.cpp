#include <bits/stdc++.h>
using namespace std;
#define newl "\n"

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    int seat2 = 2 * n; 
    int seat4= n;
    
    int a1, a2;
    a1 = a2 = 0;
    int s;
    bool res = true;
    while (k--) {
        cin >> s;
        if(s >= 4) {
            int g4 = s/4;
            if (seat4 >= g4) {
                s %= 4;
                seat4 -= g4;
            } else {
                s -= (seat4 * 4);
                seat4 = 0;
            } 

            if (s >= 4) {
                a2 += (s/2);
                a1 += (s%2);
                s = 0;
            }
        }

        if (s == 3) {
            if (seat4) {
                s = 0;
                --seat4;
            } else {
                ++a2;
                ++a1;
            }
        }
        else if (s == 2)
            ++a2;
        else if (s == 1)
            ++a1;
    }

    if (seat4) {
        int ac = min(min(a1, a2), seat4);
        a2 -= ac; 
        a1 -= ac;
        seat4 -= ac;
    } 

    if (seat4) {
        if (a1) {
            int ac = min(seat4, a1/2);
            seat4 -= ac;
            a1 -= (ac*2);
        } else if (a2) {
            int ac = min(seat4/2, a2/3);
            seat4 -=  (ac*2);
            a2 -= (ac*3);
        }
    }

    if (seat2) { 
        int ac = min(seat2, a2);
        seat2 -= ac;
        a2 -= ac;
    } 
    if (seat2) {
        int ac = min(seat2, a1);
        seat2 -= ac;
        a1 -= ac;
    } 
    if (a1 || a2)
        cout << "NO" << newl;
    else
        cout << "YES" << newl;
    return 0;
}
