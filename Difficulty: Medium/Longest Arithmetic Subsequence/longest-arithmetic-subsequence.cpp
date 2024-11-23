//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int lengthOfLongestAP(vector<int>& arr) {
        // code here
        int n = arr.size();
        if (n <= 2) return n;

        vector<unordered_map<int, int>> dp(n);

        int maxLength = 2;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = arr[i] - arr[j];
                dp[i][diff] = dp[j].count(diff) ? dp[j][diff] + 1 : 2;
                maxLength = max(maxLength, dp[i][diff]);
            }
        }

        return maxLength;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.lengthOfLongestAP(arr);
        cout << ans << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends