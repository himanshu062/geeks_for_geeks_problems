//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    string convert(string s, int n) {
        //code
        if (n == 1) return s;

        vector<string> rows(min(n, (int)s.size()));
        int currRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[currRow] += c;
            if (currRow == 0 || currRow == n - 1) goingDown = !goingDown;
            currRow += goingDown ? 1 : -1;
        }

        string result;
        for (string row : rows) result += row;
        return result;
        
    }
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while (t--){
        string str;
        cin>>str;
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.convert(str, n)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends