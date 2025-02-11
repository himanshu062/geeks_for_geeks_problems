//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long long numberOfSubsequences(int N, long long A[]){
        // code here 
         const int MOD = 1e9 + 7;
        long long count = 0;
        
        for(int i = 0; i < N; i++) {
            if ((A[i] & (A[i] - 1)) == 0) count++;
        }
        
        long long result = 1;
        while (count--) {
            result = (result * 2) % MOD;
        }
        
        return (result - 1 + MOD) % MOD;
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
        cin >> N;
        long long A[N];
        for(int i=0;i<N;++i){
            cin >> A[i];
        }
        Solution ob;
        cout << ob.numberOfSubsequences(N,A) << endl;
    
cout << "~" << "\n";
}
    return 0; 
} 
// } Driver Code Ends