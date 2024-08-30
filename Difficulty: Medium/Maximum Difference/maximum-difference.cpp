//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        vector<int> leftSmaller(n), rightSmaller(n);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && s.top() >= arr[i]) {
                s.pop();
            }
            leftSmaller[i] = (s.empty()) ? 0 : s.top();
            s.push(arr[i]);
        }
        while (!s.empty()) s.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && s.top() >= arr[i]) {
                s.pop();
            }
            rightSmaller[i] = (s.empty()) ? 0 : s.top();
            s.push(arr[i]);
        }
        int maxDiff = 0;
        for (int i = 0; i < n; i++) {
            maxDiff = max(maxDiff, abs(leftSmaller[i] - rightSmaller[i]));
        }

        return maxDiff;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends