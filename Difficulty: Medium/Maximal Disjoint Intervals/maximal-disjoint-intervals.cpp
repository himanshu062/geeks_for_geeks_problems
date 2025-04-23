//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>> maxDisjointInterval(vector<vector<int>> &arr) {
        // code here
        sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        vector<vector<int>> result;
        int lastEnd = -1;
        
        for (const auto& interval : arr) {
            if (interval[0] > lastEnd) {
                result.push_back(interval);
                lastEnd = interval[1];
            }
        }
        
        return result;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> arr(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> arr[i][0] >> arr[i][1];
        }
        Solution obj;
        vector<vector<int>> ans = obj.maxDisjointInterval(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i][0] << " " << ans[i][1] << endl;
        }
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends