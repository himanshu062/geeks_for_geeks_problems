//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        vector<int> parent(n), rank(n, 0);
        iota(parent.begin(), parent.end(), 0);
        
        function<int(int)> find = [&](int u) {
            return parent[u] == u ? u : parent[u] = find(parent[u]);
        };
        
        auto unite = [&](int u, int v) {
            int pu = find(u), pv = find(v);
            if (pu == pv) return false;
            if (rank[pu] > rank[pv]) swap(pu, pv);
            parent[pu] = pv;
            if (rank[pu] == rank[pv]) rank[pv]++;
            return true;
        };
        
        int extraEdges = 0, components = n;
        for (auto& e : edge) {
            if (!unite(e[0], e[1])) extraEdges++;
        }
        
        unordered_set<int> uniqueRoots;
        for (int i = 0; i < n; i++) uniqueRoots.insert(find(i));
        components = uniqueRoots.size();
        
        return extraEdges >= components - 1 ? components - 1 : -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends