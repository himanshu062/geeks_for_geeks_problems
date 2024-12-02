//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    void dfs(int node, vector<int> adj[], vector<bool>& visited) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        vector<int> tempAdj[V];
        
        for (int i = 0; i < V; i++) {
            for (int neighbor : adj[i]) {
                if ((i == c && neighbor == d) || (i == d && neighbor == c)) {
                    continue;
                }
                tempAdj[i].push_back(neighbor);
            }
        }
        
        vector<bool> visited(V, false);
        dfs(c, tempAdj, visited);
        
        return !visited[d];
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    
cout << "~" << "\n";
}

    return 0;
}


// } Driver Code Ends