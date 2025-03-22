//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int countSubstring(string s) {
        // Code here
        int count[3] = {0, 0, 0}; 
        int left = 0, right = 0, total = 0, n = s.length();

        for (right = 0; right < n; ++right) {
            count[s[right] - 'a']++; 
            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                total += (n - right); 
                count[s[left] - 'a']--;
                left++;
            }
        }
        
        return total;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution obj;
        cout << obj.countSubstring(s) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends