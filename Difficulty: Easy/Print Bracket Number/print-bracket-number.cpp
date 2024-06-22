//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    vector<int> bracketNumbers(string str) {
        // Your code goes here
    vector<int> result;
    vector<int> bracketIndex(str.size(), 0);
    int bracketCounter = 1;
    int j = 0;

    for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] == '(') {
            bracketIndex[j++] = bracketCounter;
            result.push_back(bracketCounter);
            bracketCounter++;
        } 
        else if (str[i] == ')') 
            result.push_back(bracketIndex[--j]);
    }
    
    return result;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;

        vector<int> ans = ob.bracketNumbers(s);

        for (auto i : ans)
            cout << i << " ";

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends