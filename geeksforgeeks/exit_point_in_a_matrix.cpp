#include <bits/stdc++.h>
using namespace std;
# define LT 0
# define UP 1
# define RT 2
# define DN 3
struct node {
    int x, y;  
};

node findExit(int **mat, int n, int m) {
    int dir = RT;
    node cur = {0 , 0}, prev;
    while (cur.x >= 0 && cur.x < n && cur.y >= 0 && cur.y < m) {
        prev.x = cur.x;
        prev.y = cur.y;
        if (mat[cur.x][cur.y] == 0) {
            if (dir == RT) {
                ++cur.y;
            } else if (dir == LT) {
                --cur.y;
            } else if (dir == UP) {
                --cur.x;
            } else {
                ++cur.x;
            }
        } else {
            mat[cur.x][cur.y] = 0;
            dir = (dir + 1) % 4;
        }
    }
    
   return prev;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
	    int n, m;
	    cin >> n >> m;
	    int **mat = new int *[n];
	    for (int i=0; i<n; ++i)
	        mat[i] = new int [m];
	    for (int i=0; i<n; ++i)
	        for (int j=0; j<m; ++j)
	            cin >> mat[i][j];
	    node ei = findExit(mat, n, m);
	    cout << ei.x << " " << ei.y << endl;
	    for (int i=0; i<n; ++i)
	        delete mat[i];
	    delete mat;
	}
	return 0;
}
