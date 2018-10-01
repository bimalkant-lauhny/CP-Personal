int dfs(list<int>* &adj, int u, bool *recStack, bool *visited) {
    visited[u] = true;
    recStack[u] = true;
    for (auto i=adj[u].begin(); i!=adj[u].end(); ++i) {
        int v = *i;
        if (visited[v] && recStack[v])
            return v;
        if (!visited[v]) {
            int cycleAt = dfs(adj, v, recStack, visited);
            if (cycleAt != -1)
                return cycleAt;
        }
    }
    recStack[u] = false;
    return -1;
}

bool Graph :: isCyclic()
{
    bool recStack[V], visited[V];
    fill(recStack, recStack+V, false);
    fill(visited, visited+V, false);
    for (int i=0; i<V; ++i) {
        if (!visited[i]) {
            int cycleAt = dfs(adj, i, recStack, visited);
            if (cycleAt != -1) {
                fill(recStack, recStack+V, false);
                fill(visited, visited+V, false);
                dfs(adj, cycleAt, recStack, visited);
                cout << "Cycle edges: ";
                for (int i=0; i<V; ++i) {
                    if (recStack[i])
                        cout << i << " ";
                }
                cout << endl;
                return true;
            }
        }
    }
    return false;
}
