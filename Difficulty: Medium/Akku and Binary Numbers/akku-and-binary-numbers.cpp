//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    vector<long long> nums;
    
    void precompute() {
        for (int i = 0; i < 63; i++) {
            for (int j = i + 1; j < 63; j++) {
                for (int k = j + 1; k < 63; k++) {
                    nums.push_back((1LL << i) | (1LL << j) | (1LL << k));
                }
            }
        }
        sort(nums.begin(), nums.end());
    }
    
    long long solve(long long l, long long r) {
        return upper_bound(nums.begin(), nums.end(), r) - lower_bound(nums.begin(), nums.end(), l);
    }
    
};



//{ Driver Code Starts.

int main()
{
    int t;
    Solution ob;
    ob.precompute();
    cin>>t;
    while(t--)
    {
        long long l,r;
        cin>>l>>r;
        cout << ob.solve(l, r) << endl; 
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends