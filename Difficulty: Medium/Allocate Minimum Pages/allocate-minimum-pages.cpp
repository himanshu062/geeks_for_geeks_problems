//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    bool possible(long long mid, int arr[], int n, int m) {
        long long curr = 0;
        m--;
        for(int i = 0; i < n; i++) {
            if(arr[i] > mid)
                return false;
            curr += arr[i];
            if(curr > mid) {
                curr = arr[i];
                m--;
            }
        }
        return m >= 0;
    }
    // Function to find minimum number of pages.
    long long findPages(int n, int arr[], int m) {
        if(m > n)
            return -1;
        long long lo = 0, hi = 1e18;
        long long ans = -1;
        while(lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            if(possible(mid, arr, n, m)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}

// } Driver Code Ends