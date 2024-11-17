//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maximumSumRectangle(vector<vector<int>> &mat) {
        // code here
        int R = mat.size();
        int C = mat[0].size();
        int maxSum = INT_MIN;

        for (int left = 0; left < C; ++left) {
            vector<int> temp(R, 0);

            for (int right = left; right < C; ++right) {
                for (int i = 0; i < R; ++i) {
                    temp[i] += mat[i][right];
                }

                int currentSum = 0, localMax = INT_MIN;

                for (int i = 0; i < R; ++i) {
                    currentSum += temp[i];
                    localMax = max(localMax, currentSum);
                    if (currentSum < 0) currentSum = 0;
                }

                maxSum = max(maxSum, localMax);
            }
        }

        return maxSum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(v) << "\n";
    }
}
// } Driver Code Ends