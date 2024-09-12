//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string S)
{
    // your code here
     vector<int> lastIndex(256, -1);
        int maxLength = 0, start = 0;

        for (int i = 0; i < S.length(); i++) {
            start = max(start, lastIndex[S[i]] + 1);
            maxLength = max(maxLength, i - start + 1);
            lastIndex[S[i]] = i;
        }

        return maxLength;
}