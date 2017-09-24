#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int A[6], B[6];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    fill(A, A+6, 0);
    fill(B, B+6, 0);

    int n;
    cin >> n;
    int grade;
    for (int i=1; i<=n; ++i) {
        cin >> grade; 
        ++A[grade];

    }

    for (int i=1; i<=n; ++i) {
        cin >> grade; 
        ++B[grade];
    }

    int res = 0;
    int tot = 0;
    for (int i=1; i<=5; ++i) { 
        int diff = abs(A[i] - B[i]);
        if (diff & 1 != 0){
            res = -1;
            break;
        }
        else {
            tot += diff;
        }
    }

    if (res == -1 || tot%4 != 0)
        cout << -1;
    else
        cout << tot/4 << endl;
    return 0;
}
