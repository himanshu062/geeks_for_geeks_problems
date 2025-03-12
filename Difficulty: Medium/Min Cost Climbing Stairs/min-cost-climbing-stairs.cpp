//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Back-end complete function Template for C++

class Solution {
  public:
    int func(vector<int> &cost, int i, int n, vector<int> &dp) {
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int one = 1e6, two = 1e6;
            one = cost[i] + func(cost, i + 1, n, dp);
            two = cost[i] + func(cost, i + 2, n, dp);
        
        return dp[i] = min(one, two);
    }
  
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp1(n + 1, 0), dp2(n + 1, 0);
        for(int i = n - 1; i >= 0; i--) {
            int one = 1e6, two = 1e6;
            one = cost[i] + dp1[i + 1];
            two = cost[i] + dp1[i + 2];
        
             dp1[i] = min(one, two);
        }
        return min(dp1[0], dp1[1]);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution sln;
        int res = sln.minCostClimbingStairs(arr);
        cout << res << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends