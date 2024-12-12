//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int repeatedStringMatch(string a, string b) {
        // Your code goes here
        string repeated = a;
        int count = 1;

        while (repeated.size() < b.size()) {
            repeated += a;
            count++;
        }

        if (repeated.find(b) != string::npos) return count;

        repeated += a;
        count++;

        if (repeated.find(b) != string::npos) return count;

        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A;
        cin >> B;
        Solution obj;
        cout << obj.repeatedStringMatch(A, B) << "\n";
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends