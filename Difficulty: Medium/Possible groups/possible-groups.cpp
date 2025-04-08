//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    long long findgroups(vector<int> &arr) {
        // Your code goes here.
        long long c0 = 0, c1 = 0, c2 = 0;
        for(int x : arr) {
            if(x % 3 == 0) c0++;
            else if(x % 3 == 1) c1++;
            else c2++;
        }
        long long res = 0;
        res += (c0 * (c0 - 1)) / 2;
        res += c1 * c2;
        res += (c0 * (c0 - 1) * (c0 - 2)) / 6;
        res += (c1 * (c1 - 1) * (c1 - 2)) / 6;
        res += (c2 * (c2 - 1) * (c2 - 2)) / 6;
        res += c0 * c1 * c2;
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        auto ans = ob.findgroups(arr);
        cout << ans << "\n";
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends