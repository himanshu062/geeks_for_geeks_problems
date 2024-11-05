//{ Driver Code Starts
//Initial template for C++


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    string ExcelColumn(int N)
    {
        // Your code goes here
        string result = "";
    while (N > 0) {
        N--;
        result = char('A' + (N % 26)) + result;
        N /= 26;
    }
    return result;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.ExcelColumn(n)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
    
// } Driver Code Ends