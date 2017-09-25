#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string n;
    int k;
    cin >> n >> k;

    int zeros = 0, erase = 0;

    if (n.size() <= k) {
        cout << n.size() - 1 << endl;
    } else {
        int i=n.size()-1;
        while(zeros < k && i >= 0){
            if (n[i] == '0')
                ++zeros;
            else
                ++erase;
            --i;
        }
        if (zeros < k)
            cout << n.size() - 1 << endl;
        else
            cout << erase << endl;
    }
    return 0;
}
