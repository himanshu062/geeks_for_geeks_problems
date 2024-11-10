//{ Driver Code Starts
// C++ program to find all distinct palindrome sub-strings
// of a given string
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
  public:
    int palindromeSubStrs(string str) {
        // code here
        int n = str.size();
        unordered_set<string> palindromes;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; i - j >= 0 && i + j < n && str[i - j] == str[i + j]; ++j) {
                palindromes.insert(str.substr(i - j, 2 * j + 1));
            }
            for (int j = 0; i - j >= 0 && i + j + 1 < n && str[i - j] == str[i + j + 1]; ++j) {
                palindromes.insert(str.substr(i - j, 2 * j + 2));
            }
        }

        return palindromes.size();
    }
};

//{ Driver Code Starts.

// Driver program
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.palindromeSubStrs(str) << endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends