//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution{
public:
    vector<int> specialXor(int N, int Q, int a[], vector<int> query[])
    {
        // code here
        vector<int> result;
        vector<long long> prefixXor(N + 1, 0);
        
        for(int i = 0; i < N; i++) {
            prefixXor[i + 1] = prefixXor[i] ^ a[i];
        }
        
        for(int i = 0; i < Q; i++) {
            int L = query[i][0] - 1;
            int R = query[i][1] - 1;
            
            long long xorVal = prefixXor[N] ^ (prefixXor[R + 1] ^ prefixXor[L]);
            result.push_back(xorVal);
        }
        
        return result;
    }
}; 


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, Q;
        cin>>N>>Q;
        int a[N];
        for(int i = 0;i < N;i++)
            cin>>a[i];
        int l, r;
        vector<int> query[Q];
        for(int i = 0;i < Q;i++){
            cin>>l>>r;
            query[i].push_back(l);
            query[i].push_back(r);
        }
        
        Solution ob;
        vector<int> ans = ob.specialXor(N, Q, a, query);
        for(int u: ans)
            cout<<u<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends