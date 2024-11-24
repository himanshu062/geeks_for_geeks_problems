//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    double waterOverflow(int K, int R, int C) {
        // code here
        vector<vector<double>> glasses(R + 1, vector<double>(R + 1, 0.0));
        glasses[1][1] = K;
        for (int row = 1; row < R; ++row) {
            for (int col = 1; col <= row; ++col) {
                if (glasses[row][col] > 1.0) {
                    double excess = glasses[row][col] - 1.0;
                    glasses[row][col] = 1.0;
                    glasses[row + 1][col] += excess / 2.0;
                    glasses[row + 1][col + 1] += excess / 2.0;
                }
            }
        }
        return min(1.0, glasses[R][C]);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int K,R,C;
        
        cin>>K>>R>>C;

        Solution ob;
        cout << fixed << setprecision(6)<< ob.waterOverflow(K,R,C) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends