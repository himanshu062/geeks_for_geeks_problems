//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxProfit(vector<int>& arr, int k) {
        // Code here
        int n = arr.size();
        int hold = -arr[0], cash = 0;
        for (int i = 1; i < n; ++i) {
            hold = max(hold, cash - arr[i]);
            cash = max(cash, hold + arr[i] - k);
        }
        return cash;
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        int ans = ob.maxProfit(arr, k);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends