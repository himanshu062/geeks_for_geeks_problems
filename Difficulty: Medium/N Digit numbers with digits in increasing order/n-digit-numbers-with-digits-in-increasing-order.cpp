//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    void generate(int n, int num, int last_digit, vector<int>& result) {
        if (n == 0) {
            result.push_back(num);
            return;
        }
        for (int i = last_digit + 1; i <= 9; ++i) {
            generate(n - 1, num * 10 + i, i, result);
        }
    }

    vector<int> increasingNumbers(int n) {
        vector<int> result;
        if (n == 1) result.push_back(0);
        for (int i = 1; i <= 9; ++i) {
            generate(n - 1, i, i, result);
        }
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
        Solution ob;
        vector<int> ans = ob.increasingNumbers(N);
        for (auto num : ans) {
            cout << num << " ";
        }
        cout << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends