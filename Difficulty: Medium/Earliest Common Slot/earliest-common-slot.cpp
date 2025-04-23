//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> commonSlot(vector<vector<int>> &a, vector<vector<int>> &b, int d) {
        // Code Here
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            int start = max(a[i][0], b[j][0]);
            int end = min(a[i][1], b[j][1]);
            
            if (end - start >= d) {
                return {start, start + d};
            }
            
            if (a[i][1] < b[j][1]) {
                ++i;
            } else {
                ++j;
            }
        }
        
        return {};
    }
};


//{ Driver Code Starts.

int main() {
    string testcase;
    getline(cin, testcase);
    stringstream ss(testcase);
    int t;
    ss >> t;
    while (t--) {
        vector<vector<int>> arr1, arr2;
        string input;

        getline(cin, input);
        stringstream ss1(input);
        int a, b;
        while (ss1 >> a >> b) {
            arr1.push_back({a, b});
        }

        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> a >> b) {
            arr2.push_back({a, b});
        }

        int d;
        getline(cin, input);
        stringstream ss3(input);
        ss3 >> d;

        Solution obj;
        vector<int> ans = obj.commonSlot(arr1, arr2, d);

        if (!ans.empty()) {
            cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;
        } else {
            cout << "[]" << endl;
        }
    }
    return 0;
}

// } Driver Code Ends