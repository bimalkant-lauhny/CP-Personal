#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

bool vstd[150001];
vector <int> graph[150001];

int dfs(int u, long long &nv) {
    vstd[u] = true;
    int v;
    long long ne = graph[u].size();
    for (int i=0; i<graph[u].size(); ++i) {
        v = graph[u][i];
        if (!vstd[v])
            ne += dfs(v, ++nv);
    }
    return ne;
}

int main(void) {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    fill(vstd, vstd+150001, false);

    int n, m, u, v;
    cin >> n >> m;

    while(m--) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    long long ds, cgds, vt;
    bool flag = true;
    for (int i=1; i<=n; ++i) {
        if (!vstd[i]) {
            vt = 1;
            ds = dfs(i, vt);
            cgds = vt * (vt - 1);
            if (!(ds == cgds)) {
                flag = false;
                break;
            }
        }
    }

    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
