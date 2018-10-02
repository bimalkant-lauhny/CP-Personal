#include <bits/stdc++.h>
using namespace std;

int getMaxRows(int **arr, int n, int m, int k) {
    // count freq of zeroes for each row
    int rowZeroFreq[n];
    // set if current row is candidate row
    bool isCandRow[n];
    for (int i=0; i<n; ++i) {
        rowZeroFreq[i] = 0;
        for (int j=0; j<m; ++j) {
            if (arr[i][j] == 0)
                ++rowZeroFreq[i];
        }
        int diff = k - rowZeroFreq[i];
        if (diff >= 0 && diff % 2 == 0)
            isCandRow[i] = true;
        else
            isCandRow[i] = false;
    }

    // find number rows having same pattern - O(n*n*n)
    int patMatch[n];
    for (int i=0; i<n; ++i) {
        patMatch[i] = 0;
        if (!isCandRow[i]) {
            continue;
        }
        for (int k=0; k<n; ++k) {
            bool match = true;
            for (int j=0; j<m; ++j) {
                if (arr[i][j] != arr[k][j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                ++patMatch[i];
            }
        }
    }

    // find the type of row with max pattern matches - O(n)
    int maxcount = 0;
    for (int i=0; i<n; ++i) {
        if (maxcount < patMatch[i])
            maxcount = patMatch[i];
    }

    return maxcount;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int **arr = new int *[n];
    for (int i=0; i<n; ++i)
        arr[i] = new int [m];
    
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            cin >> arr[i][j];
        }
    }

    cout << getMaxRows(arr, n, m, k) << endl;
    return 0;
}
