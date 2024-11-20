//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int numberOfSubsequences(string S, string W){
        // code here 
        int count = 0;
        vector<bool> used(S.size(), false);
        for (int i = 0; i < S.size(); i++) {
            int k = i, j = 0;
            while (k < S.size() && j < W.size()) {
                if (S[k] == W[j] && !used[k]) {
                    used[k] = true;
                    j++;
                }
                k++;
            }
            if (j == W.size()) count++;
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S,W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S,W) << endl;
    
cout << "~" << "\n";
}
    return 0; 
} 


// } Driver Code Ends