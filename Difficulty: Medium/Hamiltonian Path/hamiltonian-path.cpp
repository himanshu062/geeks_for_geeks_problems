//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool dfs(vector<vector<int>>& adj, vector<bool>& visited, int n, int count, int curr) {
        if(count == n) return true;
        
        visited[curr] = true;
        for(int next : adj[curr]) {
            if(!visited[next]) {
                if(dfs(adj, visited, n, count + 1, next))
                    return true;
            }
        }
        visited[curr] = false;
        return false;
    }
    
    bool check(int n, int m, vector<vector<int>> edges) {
        vector<vector<int>> adj(n + 1);
        for(auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n + 1, false);
        for(int i = 1; i <= n; i++) {
            if(dfs(adj, visited, n, 1, i))
                return true;
        }
        
        return false;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, x, y;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            edges.push_back({x, y});
        }
        Solution obj;
        if (obj.check(n, m, edges)) {
            cout << "1" << endl;
        } else
            cout << "0" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends