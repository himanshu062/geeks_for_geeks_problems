//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'


// } Driver Code Ends

class Solution{
    public:
    int minTime(vector<pair<int, int>> &dependency, int duration[], int n, int m) {
        // 	Write your code here
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        
        for(auto &dep : dependency) {
            adj[dep.first].push_back(dep.second);
            indegree[dep.second]++;
        }
        
        queue<int> q;
        vector<int> completionTime(n, 0);
        
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
                completionTime[i] = duration[i];
            }
        }
        
        int processed = 0;
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            processed++;
            
            for(int next : adj[curr]) {
                completionTime[next] = max(completionTime[next], completionTime[curr] + duration[next]);
                if(--indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        
        if(processed != n) return -1;
        
        return *max_element(completionTime.begin(), completionTime.end());
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, x, y;
        cin >> n >> m;
        int duration[n + 5];
        vector<pair<int, int>> dependency;
        for (int i = 0; i < n; i++) cin >> duration[i];
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            dependency.push_back({x, y});
        }
        Solution obj;
        cout << obj.minTime(dependency, duration, n, m) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends