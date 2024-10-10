//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        // Code here
        int n = arr.size();
        unordered_map<int, int> firstOccurrence;  
        int maxDist = 0; 
        for (int i = 0; i < n; i++) {
            int num = arr[i];
            if (firstOccurrence.find(num) == firstOccurrence.end()) {
                firstOccurrence[num] = i;
            } else {
                int dist = i - firstOccurrence[num];
                maxDist = max(maxDist, dist);
            }
        }

        return maxDist;
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

        stringstream s1(input);
        int num;
        while (s1 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxDistance(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends