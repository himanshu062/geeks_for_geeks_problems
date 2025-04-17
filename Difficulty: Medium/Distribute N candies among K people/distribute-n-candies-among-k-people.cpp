//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function Template for C++

class Solution {
  public:
    vector<long long> distributeCandies(int N, int K) {
        // code here
        vector<long long> res(K, 0);
        long long candies = N;
        long long turn = 0;
        long long give = 1;

        while (candies > 0) {
            for (int i = 0; i < K && candies > 0; i++) {
                long long current = turn * K + (i + 1);
                if (candies >= current) {
                    res[i] += current;
                    candies -= current;
                } else {
                    res[i] += candies;
                    candies = 0;
                }
            }
            turn++;
        }

        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N>>K;
        
        Solution ob;
        vector<long long> res = ob.distributeCandies(N,K);
        
        for(int i=0; i<res.size(); i++)
            cout<<res[i]<<" ";
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends