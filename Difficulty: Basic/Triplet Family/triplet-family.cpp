//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
        bool search(vector<int>&arr, int sum, int lo, int hi){
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(arr[mid]==sum) return true;
            else if(arr[mid]<sum) lo=mid+1;
            else hi=mid-1;
        }
        return false;
    }
  
    bool findTriplet(vector<int>& arr) {
        // Your code
        int n=arr.size();
        sort(arr.begin(), arr.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int sum=arr[i]+arr[j];
                if(search(arr, sum, j+1, n-1)) return true;
            }
        }
        return false;
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
        bool res = obj.findTriplet(arr);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends