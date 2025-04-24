//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int getSingle(vector<int> &arr) {
        // code here
        int N = arr.size();
        vector<int> f(32, 0);
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < 32; j++){
                f[j] += (arr[i] >> j) & 1;
            }
        }
        
        int ans = 0;
        
        for(int i = 0; i < 32; i++)
            ans += (f[i] % 3) << i;
            
        return ans;
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
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSingle(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends