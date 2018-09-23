bool isBipartite(int G[][MAX],int V)
{
    int q[101], color[V], front, rear;
    for (int i=0; i<V; ++i)
        color[i] = -1;
    
    for (int i=0; i<V; ++i) {
        if (color[i] == -1) {
            color[i] = 1;
            q[0] = i;
            front = rear = 0;
            while(front <= rear) {
                int u = q[front++];
                //cout << "Pop: " << u << endl;
                for (int v=0; v<V; ++v) {
                    if (G[u][v]) { 
                        if (color[v] == -1) {
                            q[++rear] = v;
                            //cout << "Push: " << v << endl;
                            color[v] = !color[u];
                        } else if (color[v] == color[u]) {
                            return 0;
                        }
                    }
                }
            }
            //cout << endl;
        }
    }
    return 1;
}
