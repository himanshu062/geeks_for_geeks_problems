//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < flights.size(); i++) {
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }

        queue<pair<int, pair<int, int>>> q;
        vector<int> dist(n, INT_MAX);
        q.push({0, {src, 0}});
        dist[src] = 0;

        while (!q.empty()) {
            pair<int, pair<int, int>> temp = q.front();
            q.pop();
            int stops = temp.first;
            int node = temp.second.first;
            int cost = temp.second.second;

            if (stops > K) continue;

            for (int i = 0; i < adj[node].size(); i++) {
                int next = adj[node][i].first;
                int price = adj[node][i].second;

                if (cost + price < dist[next]) {
                    dist[next] = cost + price;
                    q.push({stops + 1, {next, dist[next]}});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends