#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[2001];
        scanf("%s", s);
        //cout << "input: " << s << endl;
        int i=0;
        while(s[i]) {
            if (s[i] != '0' && s[i] != '1')
                s[i] = '2';
            ++i;
        }
        int automata[4][3] = { 
            {0, 1, 0},
            {2, 1, 0},
            {2, 3, 0},
            {2, 1, 0}
        };
        i = 0;
        int pc = 0, cs = 0;
        while(s[i]) {
            cs = automata[cs][s[i]-'0'];
            if (cs == 3)
                ++pc;
             ++i;
             //cout << "current state: " << cs << endl;
        }
        cout << pc << endl;
    }
    return 0;
}
