#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int ls, lt;
    cin >> ls >> lt;

    string s, t;
    cin >> s;
    cin >> t;
   
    vector <int> resPos, curPos;
    for (int i=0; i<ls; ++i)
       resPos.push_back(i); 

    for (int i=0; i <= lt - ls; ++i) {
        curPos.clear();
        for (int j=0; j<ls; ++j) {
            if (t[i + j] != s[j]) {
               curPos.push_back(j);
            }
        }
    
        if (resPos.size() > curPos.size()) {
            resPos = curPos;
        }
    }

    cout << resPos.size() << "\n";
    for (int i=0; i<resPos.size(); ++i)
        cout << resPos[i] + 1 << " "; 
    cout << "\n";
    return 0;
}
