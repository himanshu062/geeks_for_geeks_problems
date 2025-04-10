//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    // Function to find the minimum number of elements to be removed.
    int minRemoval(vector<int>& arr) {
        // code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int res = n;
        
        for (int i = 0; i < n; ++i) {
            int minVal = arr[i];
            int low = i, high = n - 1, ans = i;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (arr[mid] <= 2 * minVal) {
                    ans = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            
            int len = ans - i + 1;  // size of valid subarray
            res = min(res, n - len); // minimum elements to remove
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        cout << ob.minRemoval(nums) << endl;
    }
    return 0;
}

// } Driver Code Ends