//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
	public:
   	int Nth_term(int a, int r, int n){
   	    // Code here
   	    const int MOD = 1000000007;
   	    long long res = 1, base = r;
   	    int exp = n - 1;
   	    
   	    while (exp > 0) {
   	        if (exp % 2 == 1) res = (res * base) % MOD;
   	        base = (base * base) % MOD;
   	        exp /= 2;
   	    }
   	    
   	    return (a * res) % MOD;
   	}    
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, r, n;
		cin >> a >> r >> n;
		Solution ob;
		int ans = ob.Nth_term(a, r, n);
		cout << ans <<"\n";
	
cout << "~" << "\n";
}  
	return 0;
}
// } Driver Code Ends