//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string previousNumber(string S){
        // code here 
       int n = S.size(), i = n - 2;
        while (i >= 0 && S[i] <= S[i + 1]) i--;
        if (i < 0) return "-1";
        int j = n - 1;
        while (S[j] >= S[i] || (j > i && S[j] == S[j - 1])) j--;
        swap(S[i], S[j]);
        return (S[0] == '0') ? "-1" : S;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.previousNumber(S) << endl;
    
cout << "~" << "\n";
}
    return 0; 
} 
// } Driver Code Ends