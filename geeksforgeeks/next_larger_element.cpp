#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        long long arr[n];
        for (int i=0; i<n; ++i) {
            cin >> arr[i];
        }

        long long nextLarger[n];
        nextLarger[n-1] = -1;
        stack <long long> st;
        st.push(arr[n-1]);
        for (int i=n-2; i>=0; --i) {
            while(!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                nextLarger[i] = -1;
            } else {
                nextLarger[i] = st.top();
            }
            st.push(arr[i]);
        }

        for(int i=0; i<n; ++i) {
            cout << nextLarger[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
