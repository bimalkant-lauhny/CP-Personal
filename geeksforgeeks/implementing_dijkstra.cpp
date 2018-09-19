void dijkstra(int graph[MAX][MAX], int s,int V)
{
    bool isPermanent[V];
    int shortestPath[V];
    for (int i=0; i<V; ++i) {
        isPermanent[i] = false;
        shortestPath[i] = INT_MAX;
    }
    shortestPath[s] = 0;
    for (int i=0; i<V; ++i) {
        // find new permanent node
        int u = -1;
        for (int j=0; j<V; ++j) {
            if (!isPermanent[j]) {
                if (u == -1 || shortestPath[j] < shortestPath[u]) {
                    u = j;
                }
            }
        }
        isPermanent[u] = true;
        
        // adjust new shortest paths from u
        for (int j=0; j<V; ++j) {
            if (graph[u][j] && shortestPath[u] + graph[u][j] < shortestPath[j]) {
                shortestPath[j] = shortestPath[u] + graph[u][j];
            }
        }
    }
    
    for (int i=0; i<V; ++i) {
        cout << shortestPath[i] << " ";
    }
}
