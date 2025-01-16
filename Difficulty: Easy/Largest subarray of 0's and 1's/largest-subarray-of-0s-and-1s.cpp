//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxLen(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        
        for(int i=0;i<n;i++){
            if(arr[i] == 0){
                arr[i] = -1;
            }
        }
        
        unordered_map<int,int> mp;
        int res = 0;
        int presum = 0;
        
        for(int i=0;i<n;i++){
            presum += arr[i];
            
            if(presum == 0){
                res = i+1;
            }
            
            if(mp.find(presum) == mp.end()){
                mp[presum] = i;
            }
            
            if(mp.find(presum) != mp.end()){
                res = max(res,i-mp[presum]);
            }
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore(); // To ignore the newline character after reading T

    while (T--) {
        string line;
        getline(cin, line); // Read the whole line for the array

        // Convert the line into an array of integers
        stringstream ss(line);
        vector<int> a;
        int num;
        while (ss >> num) {
            a.push_back(num);
        }

        // Create the solution object
        Solution obj;

        // Call the maxLen function and print the result
        cout << obj.maxLen(a) << endl;
    }

    return 0;
}
// } Driver Code Ends