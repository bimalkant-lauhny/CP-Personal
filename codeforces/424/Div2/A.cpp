#include <bits/stdc++.h>
using namespace std;

#define NONE 0
#define INC 1
#define CONSTT 2
#define DEC 3

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    int arr[n];
    for (int i=0; i<n; ++i) {
        cin >> arr[i];
    }
    
    if (n == 1) {
        cout << "YES\n";
        return 0;
    }

    int pos1 = 0;
    int pos2 = n - 1;
    
    while (pos1 + 1 < n && arr[pos1 + 1] > arr[pos1]) {
        ++pos1;
    }

    while (pos2 - 1 >= 0  && arr[pos2 - 1] > arr[pos2]) {
        --pos2;
    }
    
    bool is_um = false;
    int val = arr[pos1];
    is_um = true;
    for (int i=pos1+1; i<=pos2; ++i){
        if (arr[i] != val) {
            is_um = false;
            break;
        }         
    }
    if (is_um)
        cout << "YES\n";
    else 
        cout << "NO\n";

    return 0;
}
