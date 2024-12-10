//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int firstElement(vector<int>& arr, int k) {
        // write code here
        unordered_map<int, int> freq; 
        unordered_set<int> checked;  
        for (int num : arr) {
            freq[num]++;
        }

        for (int num : arr) {
            if (freq[num] == k && checked.find(num) == checked.end()) {
                return num;
            }
            checked.insert(num);
        }

        return -1;
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
        int ans = ob.firstElement(arr, k);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends