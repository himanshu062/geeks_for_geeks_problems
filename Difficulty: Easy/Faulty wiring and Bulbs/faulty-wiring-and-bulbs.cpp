//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countFlips(vector<int>& arr) {
        // code here.
        int flipCount = 0;  
        int result = 0;     

        for (int i = 0; i < arr.size(); i++) {
            if ((arr[i] == 0 && flipCount % 2 == 0) || (arr[i] == 1 && flipCount % 2 != 0)) {
                result++;  
                flipCount++; 
                
            }
        }

        return result;
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
        Solution obj;
        int res = obj.countFlips(arr);
        cout << res << endl;
        // cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends