//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        // code here
        stack<char> st;

        for (char c : s) {
            if (!st.empty() && st.top() == c) 
                st.pop();
            else 
                st.push(c); 
        }

        if (st.empty()) return "-1";

        string result = "";
        while (!st.empty()) {
            result = st.top() + result; 
            st.pop();
        }

        return result;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    
cout << "~" << "\n";
}
}

// } Driver Code Ends