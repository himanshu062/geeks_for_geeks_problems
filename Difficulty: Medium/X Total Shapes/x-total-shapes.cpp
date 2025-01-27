//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find the number of 'X' total shapes.
    int xShape(vector<vector<char>>& grid) 
    {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        auto dfs = [&](int x, int y, auto&& dfsRef) -> void {
            if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] != 'X')
                return;
            grid[x][y] = 'O';
            dfsRef(x + 1, y, dfsRef);
            dfsRef(x - 1, y, dfsRef);
            dfsRef(x, y + 1, dfsRef);
            dfsRef(x, y - 1, dfsRef);
        };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'X') {
                    count++; 
                    dfs(i, j, dfs);
                }
            }
        }

        return count;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends