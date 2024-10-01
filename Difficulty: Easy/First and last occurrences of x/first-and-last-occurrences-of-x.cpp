//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> firstAndLast(int x, vector<int> &arr) {
        // Code here
        int n = arr.size();
        int first = -1, last = -1;
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) {
            first = mid;
            right = mid - 1; 
        } else if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    left = 0;
    right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) {
            last = mid;
            left = mid + 1; 
        } else if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (first == -1) {
        return {-1};  
    }

    return {first, last};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int x;
        cin >> x;
        cin.ignore();

        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        vector<int> ans = obj.firstAndLast(x, arr);
        for (int i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends