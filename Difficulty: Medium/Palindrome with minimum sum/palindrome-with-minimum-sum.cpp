//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumSum(string S) {
        // code here
        int n = S.size();
        for (int i = 0; i < n / 2; i++) {
            if (S[i] != '?' && S[n - i - 1] != '?' && S[i] != S[n - i - 1]) 
                return -1;
            if (S[i] == '?') 
                S[i] = S[n - i - 1];
            else if (S[n - i - 1] == '?') 
                S[n - i - 1] = S[i];
        }

        char last = '?';
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (S[i] != '?') {
                if (last != '?') 
                    sum += abs(S[i] - last);
                last = S[i];
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends