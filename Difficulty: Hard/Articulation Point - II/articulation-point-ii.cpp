//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int timer;
    void dfs(int u, vector<int>& disc, vector<int>& low, vector<int>& parent, vector<vector<int>>& adj, vector<bool>& ap) {
        disc[u] = low[u] = timer++;
        int children = 0;

        for (int v : adj[u]) {
            if (disc[v] == -1) { // Not visited
                parent[v] = u;
                children++;
                dfs(v, disc, low, parent, adj, ap);

                low[u] = min(low[u], low[v]);

                // Case 1: u is root of DFS tree and has two or more children
                if (parent[u] == -1 && children > 1)
                    ap[u] = true;

                // Case 2: u is not root and low[v] >= disc[u]
                if (parent[u] != -1 && low[v] >= disc[u])
                    ap[u] = true;
            }
            else if (v != parent[u]) {
                // Back edge
                low[u] = min(low[u], disc[v]);
            }
        }
    }

    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u); // undirected
        }

        vector<int> disc(V, -1), low(V, -1), parent(V, -1);
        vector<bool> ap(V, false);
        timer = 0;

        for (int i = 0; i < V; i++) {
            if (disc[i] == -1) {
                dfs(i, disc, low, parent, adj, ap);
            }
        }

        vector<int> result;
        for (int i = 0; i < V; i++) {
            if (ap[i])
                result.push_back(i);
        }

        if (result.empty()) return {-1};
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }
        Solution obj;
        vector<int> ans = obj.articulationPoints(V, edges);
        sort(ans.begin(), ans.end());
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends