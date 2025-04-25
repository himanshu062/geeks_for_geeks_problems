//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int find(int x, vector<int>& parent) {
        if (parent[x] != x)
            parent[x] = find(parent[x], parent);
        return parent[x];
    }

    void unite(int x, int y, vector<int>& parent, vector<int>& rank) {
        int px = find(x, parent), py = find(y, parent);
        if (px == py) return;
        if (rank[px] < rank[py]) parent[px] = py;
        else if (rank[px] > rank[py]) parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
    }

    int kruskalsMST(int V, vector<vector<int>> &edges) {
        sort(edges.begin(), edges.end(), [](auto &a, auto &b) { return a[2] < b[2]; });
        vector<int> parent(V), rank(V, 0);
        iota(parent.begin(), parent.end(), 0);
        int mstWeight = 0;
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            if (find(u, parent) != find(v, parent)) {
                unite(u, v, parent, rank);
                mstWeight += w;
            }
        }
        return mstWeight;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
        }

        Solution obj;
        cout << obj.kruskalsMST(V, edges) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends