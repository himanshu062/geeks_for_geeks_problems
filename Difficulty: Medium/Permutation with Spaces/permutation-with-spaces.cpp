//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    void generatePermutations(string s, string current, int index, vector<string>& result) {
        if (index == s.size()) {
            result.push_back(current);
            return;
        }
        generatePermutations(s, current + " " + s[index], index + 1, result);
        generatePermutations(s, current + s[index], index + 1, result);
    }

    vector<string> permutation(string s) {
        vector<string> result;
        generatePermutations(s, string(1, s[0]), 1, result);
        sort(result.begin(), result.end());
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for (int i = 0; i < ans.size(); i++) {
            cout << "(" << ans[i] << ")";
        }
        cout << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends