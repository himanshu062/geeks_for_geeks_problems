//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        // code here
        int n = matrix.size(), m = matrix[0].size();
        if (matrix[xs][ys] == 0 || matrix[xd][yd] == 0) return -1;

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int maxDist = -1;
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        function<void(int, int, int)> dfs = [&](int x, int y, int dist) {
            if (x == xd && y == yd) {
                maxDist = max(maxDist, dist);
                return;
            }

            visited[x][y] = true;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && matrix[nx][ny] == 1 && !visited[nx][ny]) {
                    dfs(nx, ny, dist + 1);
                }
            }
            visited[x][y] = false;
        };

        dfs(xs, ys, 0);
        return maxDist;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends