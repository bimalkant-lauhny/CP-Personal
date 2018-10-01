int dfs(list<int>* &adj, int u, int pu, bool visited[]) {
    visited[u] = true;
    for (auto i=adj[u].begin(); i!=adj[u].end(); ++i) {
        int v = *i;
        if (!visited[v]) {
            int cycleAt = dfs(adj, v, u, visited);
            if (cycleAt != -1)
                return cycleAt;
        } else {
            if (visited[v] && v != pu)
                return v;
        }
    }
    return -1;
}

bool Graph :: isCyclic()
{
    bool visited[V];
    fill(visited, visited+V, false);
    for (int i=0; i<V; ++i) {
        if (!visited[i]) {
            int cycleAt = dfs(adj, i, -1, visited);
            if (cycleAt != -1)
                return true;
        }
    }
    return false;
}
