//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    vector<int> stableMarriage(vector<vector<int>> &men, vector<vector<int>> &women) {
        // code here
int n = men.size();

        vector<vector<int>> womanPref(n, vector<int>(n));
        for (int w = 0; w < n; ++w) {
            for (int rank = 0; rank < n; ++rank) {
                womanPref[w][women[w][rank]] = rank;
            }
        }

        vector<int> womanPartner(n, -1); 
        vector<int> manNext(n, 0);       
        vector<bool> freeMen(n, true);  

        int freeCount = n;

        while (freeCount > 0) {
            int m;
            for (m = 0; m < n; ++m) {
                if (freeMen[m]) break;
            }

            int w = men[m][manNext[m]]; 
            manNext[m]++;

            if (womanPartner[w] == -1) {
                womanPartner[w] = m;
                freeMen[m] = false;
                freeCount--;
            } else {
                int m2 = womanPartner[w];
                if (womanPref[w][m] < womanPref[w][m2]) {
                    womanPartner[w] = m;
                    freeMen[m] = false;
                    freeMen[m2] = true;
                }
            }
        }
        vector<int> manPartner(n);
        for (int w = 0; w < n; ++w) {
            manPartner[womanPartner[w]] = w;
        }

        return manPartner;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> men(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cin >> men[i][j];
        }

        vector<vector<int>> women(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cin >> women[i][j];
        }

        Solution obj;
        vector<int> res = obj.stableMarriage(men, women);
        for (int i = 0; i < n; i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
}
// } Driver Code Ends