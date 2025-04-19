//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int maxXor(vector<int> &arr) {
        // code here
        int res = 0;
        int mask = 0;
        int curr = 0;
        
        for(int i = 30; i >= 0; i--)
        {
            set<int> st;
            
            mask |= (1 << i);
            for(auto x : arr)
            {
                st.insert(x & mask);
            }
            
            curr |= (1 << i);
            bool f = 0;
            
            for(auto x : st)
            {
                if(st.find(curr ^ x) != st.end())
                {
                    f = 1;
                    break;
                }
            }
            
            if(!f) curr ^= (1 << i);
            
            res = max(res, curr);
        }
        return res;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.maxXor(arr) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends