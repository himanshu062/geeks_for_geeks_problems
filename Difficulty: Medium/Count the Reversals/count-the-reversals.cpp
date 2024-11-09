//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    
cout << "~" << "\n";
}
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string S)
{
    // your code here
    int n = S.length();
        if (n % 2 != 0) 
            return -1;
        int left = 0, right = 0;
        for (int i = 0; i < n; i++) {
            if (S[i] == '{') 
                left++; 
            else {
                if (left > 0) 
                    left--;
                else 
                    right++; 
                
            }
        }
        return (left + 1) / 2 + (right + 1) / 2;
}