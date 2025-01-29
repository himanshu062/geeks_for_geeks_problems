//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(vector<int>&arr, int n) {
	    // code here
	    if (n == 1) return arr[0];

	    int prev2 = 0, prev1 = arr[0];

	    for (int i = 1; i < n; i++) {
	        int take = arr[i] + prev2;
	        int notTake = prev1;
	        int curr = max(take, notTake);
	        prev2 = prev1;
	        prev1 = curr;
	    }

	    return prev1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int>arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends