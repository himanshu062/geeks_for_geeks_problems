//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  bool canPlaceCows(vector<int> &stalls, int n, int k, int dist) {
        int cowsPlaced = 1; 
        int lastPosition = stalls[0]; 
        for (int i = 1; i < n; i++) {
            if (stalls[i] - lastPosition >= dist) {
                cowsPlaced++;
                lastPosition = stalls[i]; 
                if (cowsPlaced == k) 
                    return true; 
            }
        }
        return false; 
    }

    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code herei
        int n = stalls.size();
        sort(stalls.begin(), stalls.end());
        int low = 1; 
        int high = stalls[n-1] - stalls[0]; 
        int ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2; 
            if (canPlaceCows(stalls, n, k, mid)) {
                ans = mid; 
                low = mid + 1; 
            } 
            else 
                high = mid - 1; 
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends