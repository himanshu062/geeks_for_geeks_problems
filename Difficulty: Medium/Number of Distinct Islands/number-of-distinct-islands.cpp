//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
     void dfs(vector<vector<int>>& grid, int x, int y, int baseX, int baseY, vector<pair<int, int>>& shape) {
        int n = grid.size(), m = grid[0].size();
        if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == 0) return;
        
        grid[x][y] = 0;
        shape.push_back({x - baseX, y - baseY});
        
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        
        for (int i = 0; i < 4; i++) {
            dfs(grid, x + dx[i], y + dy[i], baseX, baseY, shape);
        }
    }

    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        set<vector<pair<int, int>>> uniqueIslands;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    vector<pair<int, int>> shape;
                    dfs(grid, i, j, i, j, shape);
                    uniqueIslands.insert(shape);
                }
            }
        }
        
        return uniqueIslands.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends