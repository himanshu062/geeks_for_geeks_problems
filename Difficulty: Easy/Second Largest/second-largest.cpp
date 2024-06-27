//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int print2largest(int arr[], int n) {
        // code here
         if (n < 2) 
            return -1;

        int largest = INT_MIN;
        int second_largest = INT_MIN;
        bool all_same = true;

        for (int i = 0; i < n; i++) {
            if (arr[i] > largest) {
                second_largest = largest;
                largest = arr[i];
                all_same = false; 
            }
            else if (arr[i] > second_largest && arr[i] != largest) 
                second_largest = arr[i];
            else if (arr[i] != largest) 
                all_same = false;
            
        }

        if (all_same || second_largest == INT_MIN) 
            return -1;
        return second_largest;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.print2largest(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends