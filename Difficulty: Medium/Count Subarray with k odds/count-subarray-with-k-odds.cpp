//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int countSubarray(int n, vector<int>& nums, int k) {
        // Code here
        unordered_map<int, int> freq;
        freq[0] = 1;
        int count = 0, odd = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] % 2 != 0) odd++;
            if (freq.find(odd - k) != freq.end())
                count += freq[odd - k];
            freq[odd]++;
        }
        return count;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.countSubarray(n, nums, k) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends