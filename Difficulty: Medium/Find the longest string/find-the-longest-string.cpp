//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string longestString(vector<string> &arr)
    {
        // code here
        unordered_set<string> prefixes(arr.begin(), arr.end());
        sort(arr.begin(), arr.end());
        
        string result = "";
        for (const string& str : arr) {
            bool valid = true;
            for (int i = 1; i <= str.size(); i++) {
                if (prefixes.find(str.substr(0, i)) == prefixes.end()) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                if (str.size() > result.size()) {
                    result = str;
                }
            }
        }
        return result;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends