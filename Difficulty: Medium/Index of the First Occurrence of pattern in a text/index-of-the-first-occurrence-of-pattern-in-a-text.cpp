//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int findMatching(string text, string pat) {
        // Code here
        int n = text.size();
        int m = pat.size();
        
        for(int i = 0; i <= n - m; i++) {
            int j = 0;
            while(j < m && text[i + j] == pat[j]) {
                j++;
            }
            if(j == m) return i;
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string text, pat;
        cin >> text >> pat;
        Solution obj;
        cout << obj.findMatching(text, pat) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends