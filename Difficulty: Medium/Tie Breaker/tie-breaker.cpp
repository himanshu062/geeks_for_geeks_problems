//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string TieBreak(vector<string>& arr) {
        // your code here
        map<string, int> voteCount;
        for (const string& name : arr) {
            voteCount[name]++;
        }
        
        return max_element(voteCount.begin(), voteCount.end(), 
            [](const auto& a, const auto& b) {
                return a.second < b.second;
            })->first;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<string> arr;
        string s;
        while (ss >> s) {
            arr.push_back(s);
        }
        Solution ob;
        cout << ob.TieBreak(arr) << endl;
    }
}

// } Driver Code Ends