//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++

class Solution{
    public:
        vector<int> minimumTime(int n,vector<vector<int>> &edges,int m)
        {
            // code here 
            vector<int> inDegree(n + 1, 0);
            vector<int> adj[n + 1];
            for (auto &edge : edges) {
                adj[edge[0]].push_back(edge[1]);
                inDegree[edge[1]]++;
            }

            queue<int> q;
            vector<int> time(n, 0);
            for (int i = 1; i <= n; i++) {
                if (inDegree[i] == 0) {
                    q.push(i);
                    time[i - 1] = 1;
                }
            }

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (int neighbor : adj[node]) {
                    inDegree[neighbor]--;
                    if (inDegree[neighbor] == 0) {
                        time[neighbor - 1] = time[node - 1] + 1;
                        q.push(neighbor);
                    }
                }
            }

            return time;
        }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int m;
        cin>>m;
        vector<vector<int>> edges(m,vector<int>(2));
        for(int i=0;i<m;i++)
            cin>>edges[i][0]>>edges[i][1];
        Solution s;
        vector<int> ans=s.minimumTime(n,edges,m);
        for(auto j:ans)
            cout<<j<<" ";
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends