//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long int arrangeTiles(int N){
        // code here
        vector<long long> dp(N+1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= N; i++) {
            dp[i] = dp[i-1] + (i >= 4 ? dp[i-4] : 0);
        }
        return dp[N];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.arrangeTiles(N)<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends