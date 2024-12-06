//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
    //Complete the function and return minimum number of operations
    public:
    int specialPalindrome(string s1, string s2){
        //Code Here
        int n = s1.size(), m = s2.size();
        if (m > n) return -1;
        
        int minOperations = INT_MAX;

        for (int start = 0; start <= n - m; ++start) {
            string modified = s1;
            int ops = 0;

            for (int i = 0; i < m; ++i) {
                if (modified[start + i] != s2[i]) {
                    modified[start + i] = s2[i];
                    ops++;
                }
            }

            int palindromeOps = 0;
            bool isValid = true;
            for (int i = 0; i < n / 2; ++i) {
                int j = n - 1 - i;
                if (modified[i] != modified[j]) {
                    if (i >= start && i < start + m && j >= start && j < start + m) {
                        isValid = false;
                        break;
                    }
                    modified[i] = modified[j];
                    palindromeOps++;
                }
            }

            if (isValid) {
                minOperations = min(minOperations, ops + palindromeOps);
            }
        }

        return minOperations == INT_MAX ? -1 : minOperations;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        Solution obj;
        int ans = obj.specialPalindrome(s1,s2);
        
        cout<<ans<<endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends