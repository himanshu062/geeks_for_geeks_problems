//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void inorderTraversal(vector<int>& arr, vector<int>& inorder, int index, int n) {
        if (index >= n) return;
        inorderTraversal(arr, inorder, 2 * index + 1, n);
        inorder.push_back(arr[index]);
        inorderTraversal(arr, inorder, 2 * index + 2, n);
    }

    int minSwaps(vector<int>& arr) {
        int n = arr.size();
        vector<int> inorder;
        inorderTraversal(arr, inorder, 0, n);
        
        vector<pair<int, int>> sortedArr(n);
        for (int i = 0; i < n; i++) 
            sortedArr[i] = {inorder[i], i};

        sort(sortedArr.begin(), sortedArr.end());

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || sortedArr[i].second == i)
                continue;

            int cycleSize = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = sortedArr[j].second;
                cycleSize++;
            }
            swaps += (cycleSize - 1);
        }
        return swaps;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        cout << ob.minSwaps(arr) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends