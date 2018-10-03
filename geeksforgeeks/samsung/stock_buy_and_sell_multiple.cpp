#include <bits/stdc++.h>
using namespace std;

int printMaxPairs(int arr[], int n) {
    int i=0, p=0;
    while(i < n) {
        while(i < n-1 && arr[i] > arr[i+1]) ++i;
        if (i == n) break;
        int l = i;
        while(i < n-1 && arr[i] < arr[i+1]) ++i;
        if (i == n) break;
        int r = i;
        if (l != r) {
            cout << "(" << l << " " << r << ") ";
            ++p;
        }
        ++i;
    }
    if (p == 0) {
        cout << "No Profit";
    }
    cout << endl;
}

int main() {
	// start writing here
	int t;
	cin >> t;
	while(t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i=0; i<n; ++i)
            cin >> arr[i];
        printMaxPairs(arr, n);
	}
	return 0;
}
