//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    long long maxProduct(vector<int> arr) {
        // code here
        long long n = arr.size();
        long long max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        long min1 = INT_MAX, min2 = INT_MAX;
        for (int i = 0; i < n; i++) {
            long long num = arr[i];
            if (num > max1) {
                max3 = max2;
                max2 = max1;
                max1 = num;
            } else if (num > max2) {
                max3 = max2;
                max2 = num;
            } else if (num > max3) {
                max3 = num;
            }
            if (num < min1) {
                min2 = min1;
                min1 = num;
            } else if (num < min2) {
                min2 = num;
            }
        }
        return max(max1 * max2 * max3, max1 * min1 * min2);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends