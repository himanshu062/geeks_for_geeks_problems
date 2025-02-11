//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findParent(int node, vector<int>& parent) {
        if (parent[node] == node) return node;
        return parent[node] = findParent(parent[node], parent);
    }
    
    void unionNodes(int u, int v, vector<int>& parent, vector<int>& rank) {
        int pu = findParent(u, parent);
        int pv = findParent(v, parent);
        if (pu != pv) {
            if (rank[pu] > rank[pv]) parent[pv] = pu;
            else if (rank[pu] < rank[pv]) parent[pu] = pv;
            else {
                parent[pv] = pu;
                rank[pu]++;
            }
        }
    }
    
    int maxRemove(vector<vector<int>>& stones, int n) {
        unordered_map<int, int> rowMap, colMap;
        int maxRow = 0, maxCol = 0;

        for (auto& stone : stones) {
            maxRow = max(maxRow, stone[0]);
            maxCol = max(maxCol, stone[1]);
        }

        int size = maxRow + maxCol + 2;
        vector<int> parent(size), rank(size, 0);
        for (int i = 0; i < size; i++) parent[i] = i;

        for (auto& stone : stones) {
            int row = stone[0], col = stone[1] + maxRow + 1;
            unionNodes(row, col, parent, rank);
        }

        unordered_set<int> uniqueRoots;
        for (auto& stone : stones) {
            int row = stone[0], col = stone[1] + maxRow + 1;
            uniqueRoots.insert(findParent(row, parent));
        }

        return n - uniqueRoots.size();
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
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    
cout << "~" << "\n";
}
}
// } Driver Code Ends