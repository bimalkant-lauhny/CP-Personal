#include <bits/stdc++.h>
using namespace std;
int arr[1001], lis[1001];
int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    for (int i=0; i<n; ++i) {
	        cin >> arr[i];
	        lis[i] = 1;
	        for (int j=0; j<i; ++j) {
	            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
	                lis[i] = lis[j] + 1;
	            }
	        }
	    }

	    cout << *max_element(lis, lis+n) << endl;
	}
	return 0;
}
