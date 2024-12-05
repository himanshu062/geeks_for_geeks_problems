//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> findSubarray(int n, int a[]) {
        // code here
        long long maxSum = -1, currSum = 0;
        int start = 0, end = 0, currStart = 0;
        vector<int> result;
        
        for (int i = 0; i < n; i++) {
            if (a[i] >= 0) {
                currSum += a[i];
                if (currSum > maxSum || (currSum == maxSum && (i - currStart > end - start))) {
                    maxSum = currSum;
                    start = currStart;
                    end = i;
                }
            } else {
                currSum = 0;
                currStart = i + 1;
            }
        }
        
        if (maxSum == -1) return {-1};
        for (int i = start; i <= end; i++) result.push_back(a[i]);
        return result;
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
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(n, a);
        printAns(ans);
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends