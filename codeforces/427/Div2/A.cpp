#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int s, v1, v2, t1, t2; 
    cin >> s >> v1 >> v2 >> t1 >> t2;
    
    int tt1 = (s * v1) + (2 * t1);
    int tt2 = (s * v2) + (2 * t2);

    if (tt1 < tt2)
        cout << "First\n";
    else if (tt1 > tt2)
        cout << "Second\n";
    else 
        cout << "Friendship\n";

    return 0;
}
