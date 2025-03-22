//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>> findIntersection(vector<vector<int>> a, vector<vector<int>> b) {
        vector<vector<int>> result;
        int i = 0, j = 0;

        while (i < a.size() && j < b.size()) {
            int start = max(a[i][0], b[j][0]);
            int end = min(a[i][1], b[j][1]);

            if (start <= end) {
                result.push_back({start, end});
            }

            if (a[i][1] < b[j][1]) {
                i++;
            } else {
                j++;
            }
        }
        
        return result;
    }
};


//{ Driver Code Starts.

// Driver code
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

        Solution obj;
        vector<vector<int>> ans = obj.findIntersection(arr1, arr2);

        for (auto &intervals : ans) {
            cout << "[" << intervals[0] << ", " << intervals[1] << "] ";
        }
        cout << "\n";
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends