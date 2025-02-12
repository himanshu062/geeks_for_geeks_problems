//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    bool Stonegame(int n) {
        // code he
        return n % 7 != 0 && n % 7 != 2;
    }
};

//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        int n = stoi(str);

        Solution ob;
        cout << (ob.Stonegame(n) ? "Player1" : "Player2") << endl;
        // cout << "~" << endl;
    }
}

// } Driver Code Ends