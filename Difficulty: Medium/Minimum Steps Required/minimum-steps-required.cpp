//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    // Write your code here.
    int countA = 0, countB = 0, n = str.size();
    
    for (int i = 0; i < n; i++) {
        if (i == 0 || str[i] != str[i - 1]) {
            if (str[i] == 'a') countA++;
            else countB++;
        }
    }
    
    return min(countA, countB) + 1;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends