//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    string lookandsay(int n) {
        // code here
        if (n == 1) return "1";
        
        string current = "1";
        for (int i = 2; i <= n; i++) {
            string next = "";
            int count = 1;
            
            for (int j = 1; j < current.size(); j++) {
                if (current[j] == current[j - 1]) {
                    count++;
                } else {
                    next += to_string(count) + current[j - 1];
                    count = 1;
                }
            }
            next += to_string(count) + current.back();
            current = next;
        }
        
        return current;
    }   
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution obj;
        cout<<obj.lookandsay(n)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends