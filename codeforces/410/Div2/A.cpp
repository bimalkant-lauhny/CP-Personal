#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    int len = s.size();
    int lim = len / 2;
    int diff = 0;
    for (int i=0; i<lim; ++i) {
       if (s[i] != s[len-i-1]) 
           ++diff;
    }
    
    if (diff > 1)
        cout << "NO\n";
    else if (diff == 0 && len%2 == 0)
        cout << "NO \n";
    else
        cout << "YES\n";

    return 0;
}
