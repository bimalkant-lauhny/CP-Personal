#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define LIM 200001

int p[LIM], a[LIM], b[LIM], cust[LIM]; 
bool sold[LIM] = {};
vector <int> c[4];

bool compare(int i, int j) {
    return p[i] > p[j];
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
   
    for (int i=1; i<=n; ++i) 
        cin >> p[i];

    for (int i=1; i<=n; ++i) {
        cin >> a[i];
        c[a[i]].push_back(i);
    }

    for (int i=1; i<=n; ++i) {
        cin >> b[i];
        c[b[i]].push_back(i);
    }
    
    for (int i=1; i<=3; ++i)
       sort(c[i].begin(), c[i].end(), compare); 
   
    int m;
    cin >> m;
    for (int i=0; i<m; ++i) {
        cin >> cust[i];
    }

    int elem, res;
    for (int i=0; i<m; ++i) {
        res = -1;
        while (c[cust[i]].size()) {
            elem = c[cust[i]].back();
            c[cust[i]].pop_back();
            if (sold[elem])
                continue;
            else {
                res = p[elem];
                sold[elem] = true;
                break;
            }
        } 
        cout << res << " ";
    }

    cout << endl;
    return 0;
}
