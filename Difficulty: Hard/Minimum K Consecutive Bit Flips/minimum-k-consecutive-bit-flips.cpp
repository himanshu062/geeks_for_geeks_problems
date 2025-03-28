//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
        // code here
        int n = arr.size(), flips = 0, flipped = 0;
        vector<int> isFlipped(n, 0);

        for (int i = 0; i < n; i++) {
            if (i >= k) flipped ^= isFlipped[i - k];
            if (arr[i] == flipped) {
                if (i + k > n) return -1;
                flips++;
                flipped ^= 1;
                isFlipped[i] = 1;
            }
        }
        return flips;
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        cout << ob.kBitFlips(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends