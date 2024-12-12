//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int beautySum(string s) {
        // Your code goes here
        int n = s.size(), totalBeauty = 0;
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                int maxFreq = 0, minFreq = INT_MAX;
                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) {
                        maxFreq = max(maxFreq, freq[k]);
                        minFreq = min(minFreq, freq[k]);
                    }
                }
                totalBeauty += (maxFreq - minFreq);
            }
        }
        return totalBeauty;
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
        cout << obj.beautySum(s) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends