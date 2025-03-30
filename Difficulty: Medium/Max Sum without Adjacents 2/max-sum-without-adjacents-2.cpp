//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        // Code Here
        int n = arr.size();
        if (n == 1) return arr[0];
        if (n == 2) return arr[0] + arr[1];

        vector<int> dp(n, 0);
        dp[0] = arr[0];
        dp[1] = arr[0] + arr[1];
        dp[2] = max({arr[0] + arr[1], arr[1] + arr[2], arr[0] + arr[2]});

        for (int i = 3; i < n; i++)
            dp[i] = max({dp[i-1], dp[i-2] + arr[i], dp[i-3] + arr[i] + arr[i-1]});

        return dp[n-1];
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.findMaxSum(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends