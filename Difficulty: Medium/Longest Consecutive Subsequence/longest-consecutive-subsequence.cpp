//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        unordered_set<int> hst(arr.begin(), arr.end());

        int ans = 0;
        for (int i : arr) {
            int curr = 0, tmp = i, tmp2 = i - 1;

            if (hst.count(i)) {
                while (hst.count(tmp)) {
                    curr++;
                    hst.erase(tmp);
                    tmp++;
                }
                while (hst.count(tmp2)) {
                    curr++;
                    hst.erase(tmp2);
                    tmp2--;
                }
            }
            ans = max(ans, curr);
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
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends