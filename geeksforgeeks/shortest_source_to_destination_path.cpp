#include <bits/stdc++.h>
using namespace std;
struct node {
    int x, y, s;
};

int sp(int **mat, int n, int m, int x, int y) {
    if (mat[0][0] == 0)
        return -1;
    if (mat[0][0] == 1 && x == 0 && y == 0)
        return 0;
    bool visited[m][n];
    memset(visited, false, sizeof(visited[0][0])*n*m);
    int ms = -1;
    queue <node> q;
    q.push({0, 0, 0});
    visited[0][0] = true;
    while(!q.empty()) {
        node cur = q.front();
        int i = cur.x, j = cur.y;
        q.pop();
        if (i > 0 && !visited[i-1][j] && mat[i-1][j] == 1) {
            if (x == i-1 && y == j) {
                ms = cur.s+1;
                break;
            }
            q.push({i-1, j, cur.s+1});
            visited[i-1][j] = true;
        }
        if (j > 0 && !visited[i][j-1] && mat[i][j-1] == 1) {
            if (x == i && y == j-1) {
                ms = cur.s+1;
                break;
            }
            q.push({i, j-1, cur.s+1});
            visited[i][j-1] = true;
        }
        if (i < n-1 && !visited[i+1][j] && mat[i+1][j] == 1) {
            if (x == i+1 && y == j) {
                ms = cur.s+1;
                break;
            }
            q.push({i+1, j, cur.s+1});
            visited[i+1][j] = true;
        }
        if (j < m-1 && !visited[i][j+1] && mat[i][j+1] == 1) {
            if (x == i && y == j+1) {
                ms = cur.s+1;
                break;
            }
            q.push({i, j+1, cur.s+1});
            visited[i][j+1] = true;
        }
    }
    return ms; 
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int **mat = new int* [n];
        for (int i=0; i<n; ++i)
            mat[i] = new int [m];
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                cin >> mat[i][j];
            }
        }
        int x, y;
        cin >> x >> y;
        int ms = sp(mat, n, m, x, y);
        cout << ms << endl;
        for (int i=0; i<n; ++i)
            delete mat[i];
        delete mat;
    }
	return 0;
}
