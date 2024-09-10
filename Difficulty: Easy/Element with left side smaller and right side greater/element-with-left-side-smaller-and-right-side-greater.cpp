//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findElement(vector<int> &arr) {
        // Code here
        int n = arr.size();
        if (n < 3) return -1;
        vector<int> leftMax(n), rightMin(n);
        leftMax[0] = INT_MIN;
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], arr[i - 1]);
        }
        rightMin[n - 1] = INT_MAX;
        for (int i = n - 2; i >= 0; i--) {
            rightMin[i] = min(rightMin[i + 1], arr[i + 1]);
        }
        for (int i = 1; i < n - 1; i++) {
            if (leftMax[i] < arr[i] && arr[i] < rightMin[i]) {
                return arr[i];
            }
        }
        return -1;
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
        int ans = ob.findElement(arr);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends