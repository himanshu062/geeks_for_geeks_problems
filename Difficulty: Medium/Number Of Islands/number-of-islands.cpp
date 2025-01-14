//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        vector<int> result;
        vector<vector<int>> grid(n, vector<int>(m, 0));
        vector<int> parent(n * m, -1);
        vector<int> rank(n * m, 0);
        int count = 0;

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        function<int(int)> find = [&](int x) {
            if (parent[x] == -1) return x;
            return parent[x] = find(parent[x]);
        };

        auto unite = [&](int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY) {
                if (rank[rootX] > rank[rootY]) {
                    parent[rootY] = rootX;
                } else if (rank[rootX] < rank[rootY]) {
                    parent[rootX] = rootY;
                } else {
                    parent[rootY] = rootX;
                    rank[rootX]++;
                }
                count--;
            }
        };

        for (auto &op : operators) {
            int x = op[0], y = op[1];
            if (grid[x][y] == 1) {
                result.push_back(count);
                continue;
            }

            grid[x][y] = 1;
            count++;
            int cell = x * m + y;

            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1) {
                    int neighborCell = nx * m + ny;
                    unite(cell, neighborCell);
                }
            }

            result.push_back(count);
        }

        return result;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    
cout << "~" << "\n";
}
}

// } Driver Code Ends