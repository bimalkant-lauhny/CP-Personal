#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s1, s2, t1;
    cin >> s1;
    cin >> s2;
    
    char charmap[26];
    for (int i=0; i<s1.size(); ++i) {
        charmap[s1[i] - 'a'] = s2[i];
    }

    cin >> t1;
    
    char cur;
    for (int i=0; i<t1.size(); ++i) {
        if (t1[i] >=  'A' && t1[i] <= 'Z') {
            cur = t1[i] - 'A' + 'a';
            cur = charmap[cur - 'a']; 
            cur = cur - 'a' + 'A';
        } else if (t1[i] >=  'a' && t1[i] <= 'z'){
            cur = charmap[t1[i] - 'a'];
        } else {
            cur = t1[i];
        }
        t1[i] = cur;
    }
    
    cout << t1 << endl;
    return 0;
}
