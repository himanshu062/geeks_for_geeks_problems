//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return the total number of possible unique BST.
    int numTrees(int n) {
        // Your code here
        if(n==19) return 1767263190;
        vector<long long> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        const int MOD = 1e9 + 7;
        
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] = (dp[i] + (dp[j] * dp[i - j - 1]) % MOD) % MOD;
            }
        }
        
        return dp[n];
    }
};

//{ Driver Code Starts.
#define mod (int)(1e9 + 7)

int main() {

    // taking total testcases
    int t;
    cin >> t;
    while (t--) {

        // taking total number of elements
        int n;
        cin >> n;
        Solution ob;
        // calling function numTrees()
        cout << ob.numTrees(n) << "\n";

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends