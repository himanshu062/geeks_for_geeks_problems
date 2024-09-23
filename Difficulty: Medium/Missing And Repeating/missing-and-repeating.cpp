//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        long long n = arr.size();
        long long S = (long long)n * (n + 1) / 2;
        long long S2 = (long long)n * (n + 1) * (2 * n + 1) / 6;
        
        long long arr_sum = 0, arr_sum_sq = 0;
        
        for (int i = 0; i < n; i++) {
            arr_sum += (long long)arr[i];
            arr_sum_sq += (long long)arr[i] * arr[i];
        }
        
        long long A_minus_B = S - arr_sum; // A - B
        long long A_plus_B = (S2 - arr_sum_sq) / A_minus_B; // A + B
        
        long long A = (A_minus_B + A_plus_B) / 2;
        long long B = A_plus_B - A;
        
        return {(int)B, (int)A};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends