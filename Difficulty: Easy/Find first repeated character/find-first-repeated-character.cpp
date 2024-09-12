//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<firstRepChar(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends


string firstRepChar(string S)
{
    //code here.
     unordered_set<char> seen;
        
        for (char c : S) {
            if (seen.find(c) != seen.end()) 
                return string(1, c); 
            seen.insert(c);
        }
        
        return "-1"; 
}