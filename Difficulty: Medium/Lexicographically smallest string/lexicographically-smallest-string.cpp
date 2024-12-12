//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string lexicographicallySmallest(string S, int k) {
        // code here
        int n = S.size();
        if ((n & (n - 1)) == 0)
            k /= 2;
        else 
            k *= 2;
        if (k >= n) return "-1"; 
        stack<char> st;
        for (char c : S) {
            while (!st.empty() && st.top() > c && k > 0) {
                st.pop();
                k--;
            }
            st.push(c);
        }
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result.empty() ? "-1" : result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        int k;
        cin >> S >> k;
        Solution ob;
        cout << ob.lexicographicallySmallest(S, k) << endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends