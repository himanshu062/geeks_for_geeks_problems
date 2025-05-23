//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string longestPalindrome(string &S) {
        // code here
        int n= S.size();
        int start=n;
        int ans =0;
        for(int i=0;i<n;i++)
        {
            
            // for odd case
            int l=i-1;
            int r=i+1;
            int count=1;
            while(l>-1 and r<n and S[l]==S[r])
            {
                count+=2;
                ++r;
                --l;
            }
            if(count > ans){
                ans=count;
                start=l+1;
                
            }
            else if(count == ans and l+1 < start)
            start=l+1;
            
            // for even case
            l=i-1;
            r=i;
            count=0;
            while(l>-1 and r<n and S[l]==S[r])
            {
                count+=2;
                ++r;
                --l;
                
            }
            if(count>ans)
            {
                ans=count;
                start=l+1;
            }
            else if(count == ans and l+1<start)
            start=l+1;
        }
        return S.substr(start,ans);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalindrome(S) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends