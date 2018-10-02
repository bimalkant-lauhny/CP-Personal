#include <bits/stdc++.h>
using namespace std;

int findMaxHeight(int arr[], int n) {
  // map stores (diff, sum) for each subset of arr
  map<int, int> mp, tp;
  mp[0] = 0; // start from diff=0 and sum=0
  for(int i=0; i<n; ++i) {
    tp = mp; 
    for(auto it=mp.begin(); it!=mp.end(); ++it) {
        int diff = it->first, sum = it->second;
        int newsum = sum + arr[i];
        int newdiff = abs(diff + arr[i]);
        tp[newdiff] = max(tp[newdiff], newsum);
        newdiff = abs(diff - arr[i]);
        tp[newdiff] = max(tp[newdiff], newsum);
    }
    mp = tp;
  }
  return mp[0]/2;
}

int main() {
    int arr[51], n;
    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> arr[i];
    }
    cout << findMaxHeight(arr, n) << endl;
}
