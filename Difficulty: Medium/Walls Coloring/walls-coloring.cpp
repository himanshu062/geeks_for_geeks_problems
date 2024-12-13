//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minCost(vector<vector<int>> &colors, int N) {
        // Write your code here.
        vector<int> prev = colors[0];
        
        for (int i = 1; i < N; i++) {
            vector<int> curr(3);
            curr[0] = colors[i][0] + min(prev[1], prev[2]);
            curr[1] = colors[i][1] + min(prev[0], prev[2]);
            curr[2] = colors[i][2] + min(prev[0], prev[1]);
            prev = curr;
        }
        
        return min({prev[0], prev[1], prev[2]});
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    
cout << "~" << "\n";
}
}
// } Driver Code Ends