//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void segregateElements(vector<int>& arr) {
        // Your code goes here
        int  n = arr.size();
        vector<int> pos, neg;
        for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) pos.push_back(arr[i]);
        else neg.push_back(arr[i]);
    }
    int i = 0;
    for (int x : pos) arr[i++] = x;
    for (int x : neg) arr[i++] = x;
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
        ob.segregateElements(nums);

        for (int x : nums)
            cout << x << " ";
        cout << endl;
    }
}
// } Driver Code Ends