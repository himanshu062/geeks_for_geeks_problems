//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    string rremove(string s) {
        // code here
        bool has_adjacent_duplicates = false;
        string result;
        
        for (int i = 0; i < s.size(); ) {
            int j = i;
            while (j < s.size() && s[i] == s[j]) j++;

            if (j - i == 1) result += s[i];
            else has_adjacent_duplicates = true;

            i = j;
        }

        return has_adjacent_duplicates ? rremove(result) : result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.rremove(s) << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends