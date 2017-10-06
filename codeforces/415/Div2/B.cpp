#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef unsigned long long ull;

struct node {
    ull k, l;
    ull val;
} sd[100001];

bool comp(node va, node vb) {
    return va.val > vb.val;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ull n, f;
    cin >> n >> f;
    

    ull sales = 0;
    for (int i=0; i<n; ++i) {
        cin >> sd[i].k >> sd[i].l;
        sd[i].val = min(2*sd[i].k, sd[i].l) - min(sd[i].k, sd[i].l);
    }

    sort(sd, sd+n,comp);
    
    int j=0; 
    while (j<f){
        sales += min(2*sd[j].k, sd[j].l);
        ++j;
    }
    while(j<n){
        sales += min(sd[j].k, sd[j].l);
        ++j;
    }
    cout << sales << endl;
    return 0;
}
