//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++

class Solution{
    public:
    bool isScramble(string S1, string S2){
        //code here
        if (S1 == S2) return true;
        if (S1.length() != S2.length()) return false;

        int n = S1.length();
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n + 1, false)));

        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                for (int j = 0; j + len <= n; j++) {
                    if (len == 1) {
                        dp[i][j][len] = (S1[i] == S2[j]);
                    } else {
                        for (int k = 1; k < len; k++) {
                            if ((dp[i][j][k] && dp[i + k][j + k][len - k]) || 
                                (dp[i][j + len - k][k] && dp[i + k][j][len - k])) {
                                dp[i][j][len] = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
        return dp[0][0][n];
    }    
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1>>S2;
        Solution ob;
        
        if (ob.isScramble(S1, S2)) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends