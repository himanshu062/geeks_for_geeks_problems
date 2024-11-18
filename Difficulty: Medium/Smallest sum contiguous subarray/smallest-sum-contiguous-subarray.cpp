//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int smallestSumSubarray(vector<int>& a){
      //Code here
      int currentSum = 0, minSum = INT_MAX;
        for (int i = 0; i < a.size(); i++) {
            currentSum += a[i];
            minSum = min(minSum, currentSum);
            if (currentSum > 0) currentSum = 0;
        }
        return minSum;
  }
};


//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        
        int ans = ob.smallestSumSubarray(a);
        
        cout<<ans<<endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends