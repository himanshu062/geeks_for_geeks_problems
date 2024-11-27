//{ Driver Code Starts
#include<bits/stdc++.h>
#define br char xx; cin>>xx; cout<<xx<<endl;
#define lli long long int
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of characters which Ishaan must insert  
    //such that string doesn't have three consecutive same characters.
    int modified (string a)
    {
        // Your code here
        int count = 0, n = a.size(), result = 0;
        for (int i = 1; i < n; ++i) {
            if (a[i] == a[i - 1]) {
                ++count;
                if (count == 2) {
                    ++result;
                    count = 0;
                }
            } else {
                count = 0;
            }
        }
        return result;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    string a;
    while(t--){
        cin>>a;
        Solution obj;
        cout<<obj.modified(a)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends