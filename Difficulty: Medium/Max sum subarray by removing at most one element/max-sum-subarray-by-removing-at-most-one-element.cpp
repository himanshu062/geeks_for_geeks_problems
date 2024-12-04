//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to return maximum sum subarray by removing at most one element.
    int maxSumSubarray(vector<int>& arr) {
        // Your code here
        int n = arr.size();
        vector<int> forward(n), backward(n);
        forward[0] = arr[0];
        backward[n - 1] = arr[n - 1];

        for (int i = 1; i < n; ++i) {
            forward[i] = max(arr[i], forward[i - 1] + arr[i]);
        }

        for (int i = n - 2; i >= 0; --i) {
            backward[i] = max(arr[i], backward[i + 1] + arr[i]);
        }

        int maxSum = forward[0];
        for (int i = 0; i < n; ++i) {
            maxSum = max(maxSum, forward[i]);
        }

        for (int i = 1; i < n - 1; ++i) {
            maxSum = max(maxSum, forward[i - 1] + backward[i + 1]);
        }

        return maxSum;
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
        int res = obj.maxSumSubarray(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends