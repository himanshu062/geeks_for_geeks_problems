//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int Solve(int n, vector<vector<int>>& grid) {
        // code here
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = 1;
        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int maxTime = 0;

        while (!pq.empty()) {
            pair<int, pair<int, int>> current = pq.top();
            pq.pop();
            int time = current.first;
            int x = current.second.first;
            int y = current.second.second;
            maxTime = max(maxTime, time);

            if (x == n - 1 && y == n - 1) {
                return maxTime;
            }

            for (auto& dir : directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = 1;
                    pq.push({grid[nx][ny], {nx, ny}});
                }
            }
        }

        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < n; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution ob;
        cout << ob.Solve(n, adj) << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends