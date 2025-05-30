//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#define N 105
using namespace std;

void printArray(vector<int> arr, int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>>& arr, int K) {
        // code here
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for (int i = 0; i < K; i++) {
            for (int j = 0; j < K; j++) {
                minHeap.push(arr[i][j]);
            }
        }
        
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top());
            minHeap.pop();
        }
        
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        vector<vector<int>> arr(k, vector<int>(k, 0));
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                cin >> arr[i][j];
            }
        }
        Solution obj;
        vector<int> output = obj.mergeKArrays(arr, k);
        printArray(output, k * k);
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends