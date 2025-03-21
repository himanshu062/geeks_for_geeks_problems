//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the first non-repeating character in a string.
    char nonRepeatingChar(string &S) {
        // Your code here4
        unordered_map<int , int> mp;
       queue<char> que;
       for(auto i: S)
       {
           ++mp[i];
           if(mp[i]==1) que.push(i);
           while(que.size() and mp[que.front()] > 1) que.pop();
       }
       return que.size() ? que.front() : '$';
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;

    while (T--) {

        string S;
        cin >> S;
        Solution obj;
        char ans = obj.nonRepeatingChar(S);

        if (ans != '$')
            cout << ans;
        else
            cout << "-1";

        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends