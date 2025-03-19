//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int fillingBucket(int N) {
        // code here
        if (N == 1) return 1;
        if (N == 2) return 2;

        const int MOD = 100000000;
        int prev2 = 1, prev1 = 2, curr;

        for (int i = 3; i <= N; i++) {
            curr = (prev1 + prev2) % MOD;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends