//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int noOfTriangles(vector<int>& arr) {
        // Your code goes here
        int n = arr.size(), count = 0;
        sort(arr.begin(), arr.end());
        for (int i = n - 1; i >= 2; i--) {
            int l = 0, r = i - 1;
            while (l < r) {
                if (arr[l] + arr[r] > arr[i]) {
                    count += (r - l);
                    r--;
                } else l++;
            }
        }
        return count;
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
        cout << obj.noOfTriangles(arr) << endl;
    }
}

// } Driver Code Ends