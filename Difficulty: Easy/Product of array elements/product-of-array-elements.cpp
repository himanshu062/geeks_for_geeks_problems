//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // arr[] is the array
    long long int product(vector<int> &arr) {
        // code here
        ll mod = 1000000007;
        ll result = 1;
        for (int i = 0; i < arr.size(); i++) {
            result = (result * arr[i]) % mod;
        }
        return result;
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
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;

        cout << ob.product(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends