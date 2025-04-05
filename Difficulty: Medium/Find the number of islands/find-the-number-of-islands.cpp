//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    bool isValid(int row, int col, vector<vector<char>>& grid){
        return (row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size());
    }
  
    void dfs(int row, int col, vector<vector<bool>> &vis, vector<vector<char>>& grid){
        vis[row][col] = true;
        
        for(int dr=-1; dr<=1; ++dr){
            for(int dc=-1; dc<=1; ++dc){
                if(dr == 0 && dc == 0)  continue;
                int nr = row + dr, nc = col + dc;
                if(isValid(nr, nc, grid) && grid[nr][nc] == 'L' && !vis[nr][nc])
                    dfs(nr, nc, vis, grid);
            }
        }
    }
  
  public:
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size(), m = grid[0].size(), res = 0;
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        
        for(int row=0; row<n; ++row){
            for(int col=0; col<m; ++col){
                if(grid[row][col] == 'L' && !vis[row][col]){
                    ++res;
                    dfs(row, col, vis, grid);
                }
            }
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.countIslands(grid);
        cout << ans << '\n';

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends