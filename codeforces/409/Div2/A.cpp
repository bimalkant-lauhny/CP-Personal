#include <bits/stdc++.h>
using namespace std;

void interchange(string &s, int i){
    s[i] = (s[i] == 'V')?'K':'V';
}

int count_vk(string &s){
    int count = 0;
    int len = s.size();
    for (int j=1; j<len; ++j){
        if (s[j-1] == 'V' && s[j] == 'K')
            ++count;
    }
    return count;
}

int main() {
    string s;
    cin >> s;

    int len = s.size();

    int vks = count_vk(s);

    for (int i=0; i<len; ++i){
        interchange(s, i);
        vks = max(vks, count_vk(s));
        interchange(s, i);
    }

    cout << vks << endl;
    return 0;
}
