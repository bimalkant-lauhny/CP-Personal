#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int arr[50][50];

bool check_good(int r, int c, int n) {
    bool is_good = false;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            if (arr[r][c] == arr[r][i] + arr[j][c]) {
                is_good = true;
                break;
            }
        }
        if (is_good)
            break;
    }
    return is_good;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            cin >> arr[i][j];
        }
    }
    
    bool is_good = true;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            if (arr[i][j] != 1) {
                is_good = check_good(i, j, n);
                if (!is_good)
                    break;
            }
        }
        if (!is_good)
            break;
    }

    if (!is_good) 
        cout << "No" << endl;
    else 
        cout << "Yes" << endl;

    return 0;
}
