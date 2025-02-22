//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int josephus(int n, int k) {
    // code here
    if (n == 1) return 1;
    return (josephus(n - 1, k) + k - 1) % n + 1;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t-- > 0) {
        int n, k;
        cin >> n >> k;

        cout << josephus(n, k) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends