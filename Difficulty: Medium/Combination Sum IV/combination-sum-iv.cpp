//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int combinationSum4(vector<int>& arr, int key) {
        // complete the function here
        vector<int> dp(key + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= key; i++) {
            for (int num : arr) {
                if (i >= num) {
                    dp[i] += dp[i - num];
                }
            }
        }
        return dp[key];
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.combinationSum4(arr, key) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends