//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long noOfWays(int m, int n, int x) {
        // code here
        vector<vector<long long>> dp(n + 1, vector<long long>(x + 1, 0));
        dp[0][0] = 1;
        
        for (int dice = 1; dice <= n; dice++) {
            for (int sum = 1; sum <= x; sum++) {
                for (int face = 1; face <= m; face++) {
                    if (sum - face >= 0) {
                        dp[dice][sum] += dp[dice - 1][sum - face];
                    }
                }
            }
        }
        
        return dp[n][x];
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ts;
        getline(cin, ts);
        stringstream ss(ts);
        int number;
        int f = 0;
        int m, n, x;
        while (ss >> number) {
            if (f == 0)
                m = number;
            else if (f == 1)
                n = number;
            else
                x = number;
            f++;
        }

        // cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(m, n, x) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends