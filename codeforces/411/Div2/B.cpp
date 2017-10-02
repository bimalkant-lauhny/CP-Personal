#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    
    string s(200000, 'a');
    for (int i=2; i<200000; i+=4){
        s[i] = 'b', s[i+1] = 'b';
    }
    cout << s.substr(0, n)<< endl;
    return 0;
}
