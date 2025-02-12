//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int subsetXORSum(vector<int>& arr) {
        // code here
        int totalXor = 0;
        for (int num : arr) totalXor |= num;
        return totalXor * (1 << (arr.size() - 1));
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.subsetXORSum(a) << endl;
    }

    return 0;
}

// } Driver Code Ends