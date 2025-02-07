//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int countPaths(int N){
        // code here 
        const int MOD = 1e9 + 7;
        if (N == 1) return 0;

        long long o = 1, abc = 0;
        for (int i = 1; i <= N; i++) {
            long long new_o = (3 * abc) % MOD;
            long long new_abc = (2 * abc + o) % MOD;
            o = new_o;
            abc = new_abc;
        }
        
        return o;
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
        
        Solution ob;
        cout << ob.countPaths(N) << endl;
    
cout << "~" << "\n";
}
    return 0; 
}

// } Driver Code Ends