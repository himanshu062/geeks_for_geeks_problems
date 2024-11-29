//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int arrayOperations(int n, vector<int> &arr) {
        // code here
        if (find(arr.begin(), arr.end(), 0) == arr.end()) {
            return -1; 
        }
        
        int operations = 0;
        bool inNonZeroSegment = false;
        
        for (int i = 0; i < n; ++i) {
            if (arr[i] != 0) {
                if (!inNonZeroSegment) {
                    inNonZeroSegment = true;
                    operations++;
                }
            } else {
                inNonZeroSegment = false; 
            }
        }
        
        return operations;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution obj;
        int res = obj.arrayOperations(n, arr);
        
        cout<<res<<endl;
        
    
cout << "~" << "\n";
}
}

// } Driver Code Ends