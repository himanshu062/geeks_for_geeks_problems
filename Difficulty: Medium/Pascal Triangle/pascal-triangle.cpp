//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        // code here
        const int mod = 1e9 + 7;
        vector<vector<int>> ans(n, vector<int> (n, 1));
        
        for(int i = 2; i < n; i++){
            for(int j = 1; j < i; j++){
                ans[i][j] = (ans[i - 1][j - 1] + ans[i - 1][j]) % mod;
            }
        }
        
        return ans.back();
    }
};



//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends