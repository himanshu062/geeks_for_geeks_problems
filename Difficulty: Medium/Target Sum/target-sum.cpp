//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Back-end complete function Template for C++

class Solution {
  public:
    long long findTargetSumWays(int n, vector<int>& A, int target) {
        // Your code here
        const int MOD = 1e9 + 7;
        int sum = accumulate(A.begin(), A.end(), 0);
        if ((sum + target) % 2 != 0 || sum < abs(target)) return 0;
        int s1 = (sum + target) / 2;
        vector<long long> dp(s1 + 1, 0);
        dp[0] = 1;
        for (int num : A) {
            for (int j = s1; j >= num; --j) {
                dp[j] = (dp[j] + dp[j - num]) % MOD;
            }
        }
        return dp[s1];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin >> N;
        vector<int> arr(N);

        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout << ob.findTargetSumWays(N, arr, target);
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends