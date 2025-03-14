//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int count(vector<int>& coins, int sum) {
        // code here
        int N = coins.size();
        vector<vector<long long>> dp(N, vector<long long> (sum + 1, 0));
        for(int i = 0; i < N; i++) dp[i][0] = 1;
        for(int i = 0; i < N; i++){
            for(int j = 1; j < sum + 1; j++){
                long long pick, nopick;
                pick = nopick = 0;
                if(j >= coins[i]) pick = dp[i][j - coins[i]];
                if(i > 0) nopick = dp[i - 1][j];
                dp[i][j] = pick + nopick;
            }
        }
        return dp[N - 1][sum];
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
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends