//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    long long countBits(long long N) {
        // code here
        long long count = 0, power = 1;

        while (power <= N) {
            long long totalPairs = (N + 1) / (2 * power);
            long long remainder = (N + 1) % (2 * power);
            count += totalPairs * power + max(0LL, remainder - power);
            power *= 2;
        }

        return count;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        long long N;
        scanf("%lld",&N);
        
        Solution obj;
        long long res = obj.countBits(N);
        
        cout<<res<<endl;
        
    
cout << "~" << "\n";
}
}

// } Driver Code Ends