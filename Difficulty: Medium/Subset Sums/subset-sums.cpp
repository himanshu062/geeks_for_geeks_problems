//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void calculateSubsetSums(vector<int>& arr, int index, int currentSum, vector<int>& result) {
        if (index == arr.size()) {
            result.push_back(currentSum);
            return;
        }

        calculateSubsetSums(arr, index + 1, currentSum + arr[index], result);
        calculateSubsetSums(arr, index + 1, currentSum, result);
    }

    vector<int> subsetSums(vector<int> arr, int n) {
        vector<int> result;
        calculateSubsetSums(arr, 0, 0, result);
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends