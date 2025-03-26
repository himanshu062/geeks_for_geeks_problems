//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find lexicographic rank of a string.
    int findRank(string S) {
        // Your code here
        const int MOD = 1e9 + 7;
        int n = S.size();
        vector<long long> fact(n + 1, 1);
        for (int i = 2; i <= n; ++i) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        vector<int> count(26, 0);
        for (char c : S) {
            if (++count[c - 'a'] > 1) return 0;
        }
        int rank = 1;
        for (int i = 0; i < n; ++i) {
            int smaller = 0;
            for (int j = 0; j < S[i] - 'a'; ++j) {
                smaller += count[j];
            }
            rank = (rank + (smaller * fact[n - i - 1]) % MOD) % MOD;
            count[S[i] - 'a']--;
        }
        return rank;
    }
};


//{ Driver Code Starts.

int main() {
    string S;
    int t;
    cin >> t;
    while (t--) {

        cin >> S;
        Solution obj;
        cout << obj.findRank(S) << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends