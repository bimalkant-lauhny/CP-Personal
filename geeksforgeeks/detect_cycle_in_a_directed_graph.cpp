bool detectCycle(list<int> *adj, int s, bool *visited, bool *recstack) {
    visited[s] = recstack[s] = true;
    for (auto it = adj[s].begin(); it!=adj[s].end(); ++it) {
        int t = *it;
        if (!visited[t] && detectCycle(adj, t, visited, recstack))
            return true;
        else if (recstack[t])
            return true;
    }
    recstack[s] = false;
    return false;
}
/*You are required to complete this method*/
bool Graph :: isCyclic()
{   
    bool visited[V], recstack[V];
    fill(visited, visited+V+1, false);
    fill(recstack, recstack+V+1, false);
    for (int i=0; i<V; ++i) {
        if (!visited[i] && detectCycle(adj, i, visited, recstack))
            return true;
    }
    return false;
}
