//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
  public:
    string newIPAdd (string s)
    {
        //code here.
        stringstream ss(s);
        string segment, result = "";
        
        while (getline(ss, segment, '.')) {
            int i = 0;
            while (i < segment.size() && segment[i] == '0') {
                i++;
            }
            result += (i < segment.size() ? segment.substr(i) : "0") + ".";
        }
        
        result.pop_back();
        return result;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.newIPAdd (s) << endl;
    
cout << "~" << "\n";
}
}


// } Driver Code Ends