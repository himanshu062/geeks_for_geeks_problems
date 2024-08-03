//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int print2largest(vector<int> &arr) {
        // Code Here
        int largest =arr[0];
        int s_largest = INT_MIN;
        int n = arr.size();
        for(int i=1;i<n;++i){
            if(arr[i]>largest){
                s_largest = largest;
                largest = arr[i];
                
            }
            else if(arr[i]< largest && arr[i]>s_largest){
                s_largest = arr[i];
            }
        }
        return s_largest;
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
        int ans = ob.print2largest(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends