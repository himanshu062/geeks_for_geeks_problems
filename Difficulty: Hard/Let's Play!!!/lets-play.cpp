//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isSuperSimilar(int n, int m, vector<vector<int>>& mat, int x)
    {
        // code here
        vector<vector<int>> original = mat;

        for (int i = 0; i < n; i++) {
            int shift = x % m;
            if (i % 2 == 0) { 
                rotate(mat[i].begin(), mat[i].begin() + shift, mat[i].end());
            } else { 
                rotate(mat[i].begin(), mat[i].end() - shift, mat[i].end());
            }
        }

        return mat == original ? 1 : 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        int x;
        cin >> x;
        
        Solution ob;
        cout<<ob.isSuperSimilar(n,m,mat,x)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends