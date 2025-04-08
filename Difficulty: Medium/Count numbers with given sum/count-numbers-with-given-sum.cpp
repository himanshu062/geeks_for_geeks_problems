//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    const int MOD = 1e9 + 7;

    long int countWays(int n, int sum) {
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        for (int i = 1; i <= 9 && i <= sum; ++i) dp[1][i] = 1;

        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j <= sum; ++j) {
                for (int d = 0; d <= 9; ++d) {
                    if (j >= d) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - d]) % MOD;
                    }
                }
            }
        }
        return dp[n][sum] == 0 ? -1 : dp[n][sum];
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, Sum;
        cin >> n >> Sum;

        Solution ob;
        cout << ob.countWays(n, Sum) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends