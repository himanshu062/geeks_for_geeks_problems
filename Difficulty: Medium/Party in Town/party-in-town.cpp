//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution{
public:
    int bfs(int src, int N, vector<vector<int>> &adj) {
        vector<int> dist(N + 1, -1);
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        int maxDist = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int neighbor : adj[node]) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[node] + 1;
                    maxDist = max(maxDist, dist[neighbor]);
                    q.push(neighbor);
                }
            }
        }
        return maxDist;
    }

    int partyHouse(int N, vector<vector<int>> &adj) {
        int minMaxDist = INT_MAX;
        for (int i = 1; i <= N; i++) {
            minMaxDist = min(minMaxDist, bfs(i, N, adj));
        }
        return minMaxDist;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, x, y;
        cin>>N;
        vector<vector<int>> adj(N+1);
        for(int i = 0;i < N-1;i++){
            cin>>x>>y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        
        Solution ob;
        cout<<ob.partyHouse(N, adj)<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends