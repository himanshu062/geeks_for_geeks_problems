//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    bool isILRec(string &s1, string &s2, string &s3, int i, int j) {
    
    int k = i + j;
    if (i == s1.size() && j == s2.size() && k == s3.size()) 
        return true;    
    bool a = (i < s1.size()) && (s3[k] == s1[i]) &&  isILRec(s1, s2, s3, i + 1, j);
    bool b = (j < s2.size()) && (s3[k] == s2[j]) &&  isILRec(s1, s2, s3, i, j + 1);
    return a || b;
}
    bool isInterleave(string s1, string s2, string s3) 
    {
        //Your code here
        if (s1.size() + s2.size() != s3.size()) 
        return false;    
        return isILRec(s1, s2, s3, 0, 0);
    }

};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	
cout << "~" << "\n";
}
	// your code goes here
	return 0;
}
// } Driver Code Ends