//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int u, int parent, vector<int>& visited, vector<int>& discovery, vector<int>& low, vector<int>& ap, vector<int> adj[], int& timer) {
        visited[u] = 1;
        discovery[u] = low[u] = ++timer;
        int children = 0;

        for (int v : adj[u]) {
            if (!visited[v]) {
                children++;
                dfs(v, u, visited, discovery, low, ap, adj, timer);

                low[u] = min(low[u], low[v]);

                if (parent != -1 && low[v] >= discovery[u])
                    ap[u] = 1;
            } else if (v != parent) {
                low[u] = min(low[u], discovery[v]);
            }
        }

        if (parent == -1 && children > 1)
            ap[u] = 1;
    }

    vector<int> articulationPoints(int V, vector<int> adj[]) {
        vector<int> visited(V, 0), discovery(V, -1), low(V, -1), ap(V, 0);
        int timer = 0;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, -1, visited, discovery, low, ap, adj, timer);
            }
        }

        vector<int> result;
        for (int i = 0; i < V; i++) {
            if (ap[i] == 1) result.push_back(i);
        }

        return result.empty() ? vector<int>{-1} : result;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends