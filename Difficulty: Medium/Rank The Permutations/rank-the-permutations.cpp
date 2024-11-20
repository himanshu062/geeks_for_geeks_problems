//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int rank(string s) {
        // code here
        const int MOD = 1000003;
        int n = s.size();
        vector<int> fact(n + 1, 1);
        for (int i = 2; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }

        unordered_set<char> charSet;
        for (char c : s) {
            if (charSet.count(c)) return 0;
            charSet.insert(c);
        }

        int rank = 1;
        for (int i = 0; i < n; i++) {
            int countSmaller = 0;
            for (int j = i + 1; j < n; j++) {
                if (s[j] < s[i]) countSmaller++;
            }
            rank = (rank + (countSmaller * fact[n - i - 1]) % MOD) % MOD;
        }

        return rank;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.rank(S) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends