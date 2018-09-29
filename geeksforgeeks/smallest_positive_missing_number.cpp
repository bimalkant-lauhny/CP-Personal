#include <bits/stdc++.h>
using namespace std;

int swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int segregate (int *arr, int n) {
    int j = 0;
    for (int i=0; i<n; ++i) {
        if (arr[i] <= 0) {
            swap(arr[i], arr[j]);
            ++j;
        }
    }
    return j;
}

int main() {
    // start writing here
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int *arr = new int [n];
        for (int i=0; i<n; ++i) {
            cin >> arr[i];
        }
        int p = segregate(arr, n);
        cout << "After segregation:\n";
        for (int i=0; i<n; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "partition: " << p << endl;
        for (int i=0; i<p; ++i) {
            arr[i] = 1;
        }
        cout << "After abs:\n";
        for (int i=0; i<n; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
        for (int i=p; i<n; ++i) {
            cout << "We're at: " << arr[i] << endl;
            if (abs(arr[i]) <= n &&  arr[abs(arr[i])-1] > 0) {
                cout << "We entered at: " << arr[i] << endl;
                arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
            }
        }
        cout << "After pass:\n";
        for (int i=0; i<n; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
        int smi = INT_MAX;
        for (int i=0; i<n; ++i) {
            if (arr[i] > 0) {
                smi = i+1;
                break;
            }
        }
        cout << "Res: " << endl;
        cout << smi << endl;
        delete [] arr;
    }
    return 0;
}
