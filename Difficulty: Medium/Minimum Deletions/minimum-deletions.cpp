class Solution {
  public:
    int minDeletions(string s) {
        // code here
        int n = s.size();
        int dp[n][n];
        
        for(int i = n - 1; i > -1; i--){
            for(int j = i; j < n; j++){
                if(i == j){
                    dp[i][j] = 0;
                    continue;
                }
                
                if(s[i] == s[j]){
                    if(j - i == 1)
                        dp[i][j] = 0;
                    else
                        dp[i][j] = dp[i + 1][j - 1];
                }
                else{
                    dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[0][n - 1];
    }
};