class Solution {
    vector <int> parent, rank;
    public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */

    void makeSet(int n) {
        for (int i = 0; i<n; ++i) {
            parent.push_back(i);
            rank.push_back(0);
        }
    }

    int findRoot(int u) {
        // using path compression
        if (parent[u] == u)
            return u; 
        parent[u] = findRoot(parent[u]);
        return parent[u];
    }

    bool unionEdge(int u, int v) {
        int p1 = findRoot(u);
        int p2 = findRoot(v);
        if (p1 == p2) {
            // cycle detected
            return false;
        }
        if (rank[p1] == rank[p2]) {
            parent[p2] = p1;
            ++rank[p1];
        } else if (rank[p1] > rank[p2]) {
            parent[p2] = p1;
        } else {
            parent[p1] = p2;
        }
        return true;
    }

    bool validTree(int n, vector<vector<int>> &edges) {
        // write your code here
        if (edges.size() != n-1)
            return false;

        makeSet(n);
        for (auto const& e: edges) {
            if (!unionEdge(e[0], e[1]))
                return false;
        }

        return true;

    }


};
