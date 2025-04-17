//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    long long maximumProfit(vector<long long>&prices, int n) {
        // Code here
        if (n == 0) return 0;
        
        long long hold = -prices[0];  
        long long sold = 0;         
        long long rest = 0;          
        for (int i = 1; i < n; ++i) {
            long long prev_hold = hold;
            long long prev_sold = sold;
            long long prev_rest = rest;

            hold = max(prev_hold, prev_rest - prices[i]);
            sold = prev_hold + prices[i];
            rest = max(prev_rest, prev_sold);
        }

        return max(sold, rest);
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n)<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends