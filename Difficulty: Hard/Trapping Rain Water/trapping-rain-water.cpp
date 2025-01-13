//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        if (n <= 2) return 0; 
        vector<int> left_max(n), right_max(n);
        left_max[0] = arr[0];
        for (int i = 1; i < n; i++) {
            left_max[i] = max(left_max[i-1], arr[i]);
        }
        right_max[n-1] = arr[n-1];
        for (int i = n-2; i >= 0; i--) {
            right_max[i] = max(right_max[i+1], arr[i]);
        }
        long long total_water = 0;
        for (int i = 0; i < n; i++) {
            total_water += min(left_max[i], right_max[i]) - arr[i];
        }

        return total_water;
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends