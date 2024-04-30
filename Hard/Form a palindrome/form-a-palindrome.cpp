//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    private: 
    int lps(string& str,string& t,int n, int m, int i,int j,vector<vector<int>>& dp){
 if(i == n){
 return 0;
 }
 if(j == m){
 return 0;
 }
 if(dp[i][j]!=-1){
 return dp[i][j];
 }
 
 int ans = 0;
 if(str[i] == t[j]){
 ans = 1+lps(str,t,n,m,i+1,j+1,dp);
 }
 else{
 ans = max(lps(str,t,n,m,i,j+1,dp),lps(str,t,n,m,i+1,j,dp));
 }
 return dp[i][j] = ans;
 }
 
 int lpsTab(string& str,string& t,int n, int m){
 vector<vector<int>> dp(n+1,vector<int>(m+1,0));
 for(int i=n-1;i>=0;i--){
 for(int j=m-1;j>=0;j--){
 int ans = 0;
 if(str[i] == t[j]){
 ans = 1+dp[i+1][j+1];
 }
 else{
 ans = max(dp[i][j+1],dp[i+1][j]);
 }
 dp[i][j] = ans;
 }
 }
 return dp[0][0];
 }
 int lps3(string& str,string& t,int n, int m){
 //vector<vector<int>> dp(n+1,vector<int>(m+1,0));
 vector<int> curr(m+1,0);
 vector<int> next(m+1,0);
 for(int i=n-1;i>=0;i--){
 for(int j=m-1;j>=0;j--){
 int ans = 0;
 if(str[i] == t[j]){
 ans = 1+next[j+1];
 }
 else{
 ans = max(curr[j+1],next[j]);
 }
 curr[j] = ans;
 }
 next = curr;
 }
 return next[0];
 }
  public:
    int countMin(string str){
    //complete the function here
     int n = str.size();
 string t = "";
 for(int i=n-1;i>=0;i--){
 t += str[i];
 }
 vector<vector<int>> dp(n,vector<int>(n,-1));
 
 return n-lpsTab(str,t,n,n);
 return n-lps3(str,t,n,n);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends