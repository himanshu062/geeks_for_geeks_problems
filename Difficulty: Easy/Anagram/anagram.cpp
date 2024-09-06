//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string s, string t) {

        // Your code here
    if (s.length() != t.length())
      return false;

    vector<int> count(26);

    for (const char c : s)
      ++count[c - 'a'];

    for (const char c : t) {
      if (count[c - 'a'] == 0)
        return false;
      --count[c - 'a'];
    }

    return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.isAnagram(c, d))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

// } Driver Code Ends