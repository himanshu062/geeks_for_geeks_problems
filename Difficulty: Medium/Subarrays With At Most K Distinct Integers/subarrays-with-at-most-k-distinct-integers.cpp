//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int atMostK(vector<int> &arr, int k) {
        // code here
        if (k == 0) return 0;
        unordered_map<int, int> freq;
        int left = 0, right = 0, count = 0;
        
        while (right < arr.size()) {
            freq[arr[right]]++;
            
            while (freq.size() > k) {
                if (--freq[arr[left]] == 0) freq.erase(arr[left]);
                left++;
            }
            
            count += (right - left + 1);
            right++;
        }
        
        return count;
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
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution obj;
        cout << obj.atMostK(arr, k) << endl;
    }
    return 0;
}
// } Driver Code Ends