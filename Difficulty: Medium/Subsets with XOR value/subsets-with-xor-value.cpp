//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int subsetXOR(vector<int> arr, int N, int K) {
        // code here
        int maxXOR = 128;
        vector<vector<int>> dp(N + 1, vector<int>(maxXOR, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < maxXOR; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j ^ arr[i - 1]];
            }
        }
        return dp[N][K];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int K;
        cin>>K;
        vector<int> v;
        for(int i = 0;i<N;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }    
        Solution ob;
        cout << ob.subsetXOR(v,N,K) << endl;
    
cout << "~" << "\n";
}
    return 0; 
}
// } Driver Code Ends