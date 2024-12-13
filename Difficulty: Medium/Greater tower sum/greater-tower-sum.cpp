//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int SaveGotham(vector<int>& arr) {
        // Your code
        const int MOD = 1e9 + 7;
        int n = arr.size();
        stack<int> s;
        long long result = 0;

        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && s.top() <= arr[i]) {
                s.pop();
            }
            result = (result + (s.empty() ? 0 : s.top())) % MOD;
            s.push(arr[i]);
        }

        return result;
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
        int res = obj.SaveGotham(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends