class Solution {
    public:
        /**
         * @param n: n nodes labeled from 0 to n - 1
         * @param edges: a undirected graph
         * @return:  a list of all the MHTs root labels
         */
        vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
            // solution: return list of center of graph (tree here)
            // hint: a tree can have atmost 2 centers

            vector < vector <int> > graph (n);

            for (auto const &e: edges) {
                graph[e[0]].push_back(e[1]);
                graph[e[1]].push_back(e[0]);
            }

            queue <int> que;
            vector <int> level (n, 0);
            vector <int> degree (n, 0);
            int maxlevel = 0;

            for (int i=0; i<n; ++i) {
                degree[i] = graph[i].size();
                if (degree[i] == 1) {
                    que.push(i);
                }
            }

            while (!que.empty()) {
                int u = que.front();
                que.pop();
                for (int const &v: graph[u]) {
                    --degree[v];
                    if (degree[v] == 1) {
                        que.push(v);
                        level[v] = level[u] + 1;
                        maxlevel = max(maxlevel, level[v]);
                    }
                }
            }

            vector <int> centers;
            for (int i=0; i<n; ++i) {
                if (level[i] == maxlevel) {
                    centers.push_back(i);
                }
            }

            int diameter = 2 * maxlevel + centers.size() - 1;
            int radius = (diameter + 1) / 2;

            return centers;

        }
};
