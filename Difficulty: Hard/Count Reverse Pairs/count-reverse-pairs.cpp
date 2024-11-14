//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int mergeCount(vector<int>& arr, int low, int mid, int high) {
        int count = 0;
        int j = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (j <= high && arr[i] > 2LL * arr[j]) j++;
            count += (j - (mid + 1));
        }
        
        vector<int> temp;
        int left = low, right = mid + 1;
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) temp.push_back(arr[left++]);
            else temp.push_back(arr[right++]);
        }
        
        while (left <= mid) temp.push_back(arr[left++]);
        while (right <= high) temp.push_back(arr[right++]);
        
        for (int i = 0; i < temp.size(); i++) arr[low + i] = temp[i];
        
        return count;
    }
    
    int countRevPairsUtil(vector<int>& arr, int low, int high) {
        if (low >= high) return 0;
        int mid = low + (high - low) / 2;
        int count = countRevPairsUtil(arr, low, mid) + countRevPairsUtil(arr, mid + 1, high);
        count += mergeCount(arr, low, mid, high);
        return count;
    }

    int countRevPairs(int n, vector<int> arr) {
        return countRevPairsUtil(arr, 0, n - 1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countRevPairs(n, arr) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends