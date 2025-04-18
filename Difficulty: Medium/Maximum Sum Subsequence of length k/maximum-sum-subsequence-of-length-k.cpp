//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
	public:
		int max_sum(vector<int> &a, int k)
		{
		    // Code here
		    int n = a.size();
		    vector<vector<int>> dp(n, vector<int>(k+1, 0));
		    
		    for (int i = 0; i < n; i++)
		        dp[i][1] = a[i];
		    
		    for (int len = 2; len <= k; len++) {
		        for (int i = 0; i < n; i++) {
		            dp[i][len] = 0;
		            for (int j = 0; j < i; j++) {
		                if (a[j] <= a[i] && dp[j][len-1] > 0) {
		                    dp[i][len] = max(dp[i][len], dp[j][len-1] + a[i]);
		                }
		            }
		        }
		    }
		    
		    int ans = 0;
		    for (int i = 0; i < n; i++) {
		        ans = max(ans, dp[i][k]);
		    }
		    
		    return ans > 0 ? ans : -1;
		}
};




//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n, k;
    	cin >> n >> k;
    	vector<int> v(n);
    	for(int i = 0; i < n; i++)
    		cin >> v[i];
        Solution ob;
        cout<<ob.max_sum(v, k)<<"\n";
     
cout << "~" << "\n";
}
	return 0;
}


// } Driver Code Ends