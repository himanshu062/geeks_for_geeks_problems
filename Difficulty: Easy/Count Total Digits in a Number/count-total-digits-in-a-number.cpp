//{ Driver Code Starts
// Initial Template for C++

#include <iostream>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    // Complete this function
    int countDigits(int n) {
        // Your code here
        return to_string(n).length();
    }
};


//{ Driver Code Starts.

int main() {
    int T;

    // taking testcases
    cin >> T;
    while (T--) {
        int n;

        // taking number n
        cin >> n;

        // calling countDigits
        Solution obj;
        cout << obj.countDigits(n) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends