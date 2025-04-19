//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
	public:
	int TotalWays(string str){
	    // Code here
	    string target = "GEEKS";
        int n = str.size(), m = target.size();
        int mod = 1e9 + 7;
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for(int i = 0; i <= n; i++)
            dp[i][0] = 1;
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(str[i-1] == target[j-1])
                    dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % mod;
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][m];
	}

};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalWays(str);
		cout << ans <<"\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends