//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution {
public:
     bool dfs(int u, int k, const vector<vector<pair<int, int>>> &adj, vector<bool> &visited) {
        if (k <= 0) return true;
        visited[u] = true;
        for (const auto& p : adj[u]) {
            int v = p.first;
            int wt = p.second;
            if (!visited[v]) {
                if (dfs(v, k - wt, adj, visited)) return true;
            }
        }
        visited[u] = false;
        return false;
    }

    bool pathMoreThanK(int V, int E, int k, int *a) {
        vector<vector<pair<int, int>>> adj(V);
        for (int i = 0; i < 3 * E; i += 3) {
            int u = a[i], v = a[i + 1], wt = a[i + 2];
            adj[u].emplace_back(v, wt);
            adj[v].emplace_back(u, wt);
        }
        vector<bool> visited(V, false);
        return dfs(0, k, adj, visited);
    } 
};





//{ Driver Code Starts.


int main() {
	//code
    int t;cin >> t;
    while(t--)
    {
        int V, E, K;
        cin >> V >> E >> K;
        int a[3*E + 1];
        for(int  i=0;i<3*E;i++){
            cin >> a[i];
        }
        
        Solution obj;
        if(obj.pathMoreThanK(V, E, K, a)){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
        
    
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends