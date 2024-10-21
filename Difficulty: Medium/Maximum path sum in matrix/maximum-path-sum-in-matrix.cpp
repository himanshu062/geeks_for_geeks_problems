//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int n, vector<vector<int>> mat)
    {
        // code here
        vector<vector<int>> dp = mat;
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int down = dp[i-1][j];
            int down_left = (j > 0) ? dp[i-1][j-1] : 0;
            int down_right = (j < n-1) ? dp[i-1][j+1] : 0;
            dp[i][j] += max(down, max(down_left, down_right));
        }
    }
    
    int result = 0;
    for (int j = 0; j < n; j++) {
        result = max(result, dp[n-1][j]);
    }
    
    return result;

    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends