//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function template for C++


class Solution{
public:
    vector<long long> factorial(vector<long long> a, int n) {
        const long long MOD = 1000000007;
        long long maxNum = *max_element(a.begin(), a.end());
        
        vector<long long> fact(maxNum + 1);
        fact[0] = 1;
        
        for(long long i = 1; i <= maxNum; i++) {
            fact[i] = (fact[i-1] * i) % MOD;
        }
        
        vector<long long> res(n);
        for(int i = 0; i < n; i++) {
            res[i] = fact[a[i]];
        }
        
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<long long> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<long long> res = ob.factorial(a, n);
        for (i = 0; i < n; i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends