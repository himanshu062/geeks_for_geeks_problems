//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    bool isPalindrome(int n) {
        // Code here.
        int temp = n;
        int rev = 0;
        while(temp != 0){
            rev = (rev*10) + (temp%10);
            temp /= 10;
        }
        return rev == n;
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        Solution ob;
        bool ans = ob.isPalindrome(n);
        cout << (ans ? "true" : "false") << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends