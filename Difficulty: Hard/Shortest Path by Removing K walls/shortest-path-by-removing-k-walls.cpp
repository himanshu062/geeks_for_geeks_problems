//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int shotestPath(vector<vector<int>> mat, int n, int m, int k) {
        // code here
        vector<vector<int>> visited(n, vector<int>(m, -1));
        queue<tuple<int, int, int, int>> q;
        
        q.push(make_tuple(0, 0, k, 0));
        visited[0][0] = k;

        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        while (!q.empty()) {
            tuple<int, int, int, int> front = q.front();
            q.pop();
            
            int r = get<0>(front);
            int c = get<1>(front);
            int walls = get<2>(front);
            int steps = get<3>(front);
            
            if (r == n - 1 && c == m - 1) return steps;

            for (int i = 0; i < 4; i++) {
                int nr = r + directions[i][0], nc = c + directions[i][1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int remainingWalls = walls - mat[nr][nc];

                    if (remainingWalls >= 0 && visited[nr][nc] < remainingWalls) {
                        visited[nr][nc] = remainingWalls;
                        q.push(make_tuple(nr, nc, remainingWalls, steps + 1));
                    }
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
        int n, m, k, x;
        
        cin>>n>>m>>k;
        vector<vector<int>> mat;
    
        for(int i=0; i<n; i++)
        {
            vector<int> row;
            for(int j=0; j<m; j++)
            {
                cin>>x;
                row.push_back(x);
            }
            mat.push_back(row);
        }

        Solution ob;
        cout<<ob.shotestPath(mat,n,m,k);
        cout<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends