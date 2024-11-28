//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countWays(string s) {
        // Code here
        int n = s.size();
        if (n == 0 || s[0] == '0') return 0;

        const int MOD = 1e9 + 7;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; ++i) {
            int oneDigit = s[i - 1] - '0';
            int twoDigits = (s[i - 2] - '0') * 10 + oneDigit;

            if (oneDigit >= 1) {
                dp[i] = dp[i - 1];
            }

            if (twoDigits >= 10 && twoDigits <= 26) {
                dp[i] = (dp[i] + dp[i - 2]) % MOD;
            }
        }

        return dp[n];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        string s;
        cin >> s;
        Solution obj;
        int ans = obj.countWays(s);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends