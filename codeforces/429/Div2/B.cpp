#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    bool second_wins = true;

    int n;
    cin >> n;

    int i;
    while (n--) {
        cin >> i;
        if (i & 1)
            second_wins = false;
    }

    if (second_wins)
        cout << "Second" << endl;
    else
        cout << "First" << endl;
    return 0;
}
