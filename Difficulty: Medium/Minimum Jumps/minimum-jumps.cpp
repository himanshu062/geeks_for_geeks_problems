//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        int i{1},ans{1},n{static_cast<int>(arr.size())};
        if (n == 1)
            return 0;
        if (arr[0] == 0)
            return -1;
        int steps{arr[0]}, max_range{arr[0]};
       
        while (i < n-1){
           max_range = max(max_range, i + arr[i]);
           steps--;
           if (steps == 0) {
                ans++;
                if (i >= max_range)
                   return -1;
                steps = max_range - i;
            }
            i++;
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends