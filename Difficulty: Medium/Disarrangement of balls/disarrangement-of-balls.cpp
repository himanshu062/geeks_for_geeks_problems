//{ Driver Code Starts
// Initial function Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countDer(int n) {
        if (n == 1) return 0;
        if (n == 2) return 1;
        int prev2 = 0, prev1 = 1, curr = 0;
        for (int i = 3; i <= n; i++) {
            curr = (i - 1) * (prev1 + prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        Solution ob;
        cout << ob.countDer(N) << "\n";
    }
    return 0;
}
// } Driver Code Ends