#include <bits/stdc++.h>
using namespace std;
void remAdjDup(char s[]) {
    int k=0, i=1, len = strlen(s);
    while(s[i]) {
        if (s[i] != s[i-1]) {
            s[k++] = s[i-1];
        } else {
            while(s[i] == s[i-1]) ++i;
        }
        ++i;
    }
    s[k++] = s[i-1];
    s[k] = '\0';
    if (strlen(s) < len)
        remAdjDup(s);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
	    char s[51];
	    cin >> s;
	    remAdjDup(s);
	    cout << s << endl;
	}
	return 0;
}
