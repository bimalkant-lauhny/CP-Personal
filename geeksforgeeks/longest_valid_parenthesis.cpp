#include <bits/stdc++.h>
using namespace std;
int stk[100001];
char paren[100001];
int main() {
    int t;
    cin >> t;
    while (t--) {
        int top = -1;
        cin >> paren;
        int last = -1, maxvalid = 0;
        for (int i=0; paren[i]; ++i) {
            if (paren[i] == '(') {
                stk[++top] = i;
            } else {
                if (top == -1) {
                    last = i;
                } else {
                    --top;
                    if (top == -1) {
                        if (maxvalid < i - last)
                            maxvalid = i - last;
                    } else {
                        if (maxvalid < i - stk[top])
                            maxvalid = i - stk[top];
                    }
                }
            }
        }
        cout << maxvalid << endl;
    }
    return 0;
}
