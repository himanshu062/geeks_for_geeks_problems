//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int low = 0, high = arr.size() - 1;
        while (low <= high) {
            if (arr[low] <= arr[high]) return low;
            int mid = low + (high - low) / 2;
            int next = (mid + 1) % arr.size();
            int prev = (mid - 1 + arr.size()) % arr.size();
            if (arr[mid] <= arr[prev] && arr[mid] <= arr[next]) return mid;
            else if (arr[mid] >= arr[low]) low = mid + 1;
            else high = mid - 1;
        }
        return 0;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        Solution ob;
        int res = ob.findKRotation(arr);
        cout << res << endl;
    }
}
// } Driver Code Ends