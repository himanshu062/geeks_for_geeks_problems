//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // k is the maximum number of zeros allowed to flip
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int left = 0, right = 0, maxLength = 0, zeroCount = 0;

        while (right < arr.size()) {
            if (arr[right] == 0) {
                zeroCount++;
            }

            while (zeroCount > k) {
                if (arr[left] == 0) {
                    zeroCount--;
                }
                left++;
            }

            maxLength = max(maxLength, right - left + 1);
            right++;
        }

        return maxLength;
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
        int m;
        cin >> m;
        cin.ignore();

        Solution obj;
        int ans = obj.maxOnes(arr, m);
        cout << ans << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends