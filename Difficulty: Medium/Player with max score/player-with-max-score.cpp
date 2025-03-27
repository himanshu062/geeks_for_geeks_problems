//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

//User function Template for C++

class Solution{   
public:
    bool is1winner(int N,int arr[]) {
        
        // code here
        vector<vector<int>> dp(N, vector<int>(N, 0));

        for (int i = 0; i < N; i++) dp[i][i] = arr[i];

        for (int len = 2; len <= N; len++) {
            for (int i = 0, j = len - 1; j < N; i++, j++) {
                int pickLeft = arr[i] + min((i + 2 <= j ? dp[i + 2][j] : 0), (i + 1 <= j - 1 ? dp[i + 1][j - 1] : 0));
                int pickRight = arr[j] + min((i <= j - 2 ? dp[i][j - 2] : 0), (i + 1 <= j - 1 ? dp[i + 1][j - 1] : 0));
                dp[i][j] = max(pickLeft, pickRight);
            }
        }

        int totalSum = accumulate(arr, arr + N, 0);
        return dp[0][N - 1] * 2 >= totalSum;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        
        Solution ob;
        cout << ob.is1winner(N, arr) << endl;
    
cout << "~" << "\n";
}
    return 0; 
} 

// } Driver Code Ends