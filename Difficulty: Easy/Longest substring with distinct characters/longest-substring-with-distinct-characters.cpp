//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        vector<int> freq(26, 0);
        int cnt = 0;
        int n = s.length();
        
        int i = 0, j = 0;
        while(j < n) {
            freq[s[j] - 'a'] ++;
            
            while(freq[s[j] - 'a'] > 1) {
                freq[s[i] - 'a'] --;
                i ++;
            }
            
            cnt = max(cnt, j - i + 1);
            j ++;
        }
        
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends