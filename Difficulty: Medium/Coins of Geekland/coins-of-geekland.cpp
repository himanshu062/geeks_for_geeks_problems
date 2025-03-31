//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    
    public:
    int Maximum_Sum(vector<vector<int>> &mat,int N,int K){
        // Your code goes here
        vector<vector<int>> prefix(N+1, vector<int>(N+1, 0));
        
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                prefix[i][j] = mat[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
            }
        }
        
        int maxSum = INT_MIN;
        for(int i = K; i <= N; i++) {
            for(int j = K; j <= N; j++) {
                int sum = prefix[i][j] - prefix[i-K][j] - prefix[i][j-K] + prefix[i-K][j-K];
                maxSum = max(maxSum, sum);
            }
        }
        
        return maxSum;
    }  
};


//{ Driver Code Starts.

int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
    	int N;
        cin>>N;
        vector<vector<int>> mat(N,vector<int>(N,0));
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin>>mat[i][j];
            }
        }
        
        int k;cin>>k;
        Solution obj;
        cout << obj.Maximum_Sum(mat,N,k)<<"\n";
    
cout << "~" << "\n";
}
        
    return 0;
}

// } Driver Code Ends