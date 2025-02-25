//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isPatternPresent(string S, string P) {
        // code here
        if (P[0] == '^') {
            return S.find(P.substr(1)) == 0;
        } 
        if (P.back() == '$') {
            string pattern = P.substr(0, P.size() - 1);
            return S.rfind(pattern) == S.size() - pattern.size();
        }
        return S.find(P) != string::npos;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string P,S;

        cin>>P;
        cin>>S;

        Solution ob;
        cout << ob.isPatternPresent(S,P) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends