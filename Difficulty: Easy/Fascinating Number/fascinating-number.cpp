//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    bool fascinating(int n) {
        // code here
        string concatenated = to_string(n) + to_string(n * 2) + to_string(n * 3);
    if (concatenated.size() != 9) return false;
    vector<int> freq(10, 0);
    for (char c : concatenated) {
        int digit = c - '0';
        if (digit == 0 || freq[digit] > 0) return false;
        freq[digit]++;
    }
    return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.fascinating(n);

        if (ans) {
            cout << "true\n";
        } else {
            cout << "false\n";
        }
    }
    return 0;
}
// } Driver Code Ends