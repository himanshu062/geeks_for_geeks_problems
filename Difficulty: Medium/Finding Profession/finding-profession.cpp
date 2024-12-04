//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    char profession(int level, int pos){
        // code here
        int count = 0;
        pos--;
        while (pos > 0) {
            count += pos & 1;
            pos >>= 1;
        }
        return (count % 2 == 0) ? 'e' : 'd';
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int level, pos;
        cin>>level>>pos;
        
        Solution ob;
        if(ob.profession(level, pos) == 'd')
            cout<<"Doctor\n";
        else
            cout<<"Engineer\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends