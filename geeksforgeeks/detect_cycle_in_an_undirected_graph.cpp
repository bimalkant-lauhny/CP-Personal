bool detectCycle(list<int> *adj, int s, bool *visited, int parent) {
    visited[s] = true;
    for (list<int>::iterator it=adj[s].begin(); it!=adj[s].end(); ++it) {
        int t = *it;
        if (visited[t]) {
            if (t!=parent)
                return true;
        } else {
            if (detectCycle(adj, t, visited, s))
                return true;
        }
    }
    return false;
}
/*You are required to complete this method*/
bool Graph :: isCyclic()
{
    bool visited[V];
    fill(visited, visited+V+1, false);
    for (int i=0; i<V; ++i) {
        if (!visited[i]) {
            if(detectCycle(adj, i, visited, -1))
                return true;
        }
    }
    return false;
}
