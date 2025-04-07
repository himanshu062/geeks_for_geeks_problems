//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  private:
    void solve(int start, string& s, unordered_set<string>& dictSet, 
              string curr, vector<string>& result) {
        if (start == s.length()) {
            curr.pop_back();
            result.push_back(curr);
            return;
        }
        string word = "";
        for (int i = start; i < s.length(); i++) {
            word += s[i];
            if (dictSet.find(word) != dictSet.end()) {
                solve(i + 1, s, dictSet, curr + word + " ", result);
            }
        }
    }
    
public:
    vector<string> wordBreak(vector<string>& dict, string& s) {
        unordered_set<string> dictSet(dict.begin(), dict.end());
        vector<string> result;
        solve(0, s, dictSet, "", result);
        
        return result;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> dict;
        string s;
        string line;
        getline(cin, line);
        stringstream ss(line);
        while (ss >> s) {
            dict.push_back(s);
        }
        getline(cin, s);
        Solution ob;
        vector<string> ans = ob.wordBreak(dict, s);
        if (ans.size() == 0)
            cout << "[]\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++)
                cout << ans[i] << endl;
        }
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends