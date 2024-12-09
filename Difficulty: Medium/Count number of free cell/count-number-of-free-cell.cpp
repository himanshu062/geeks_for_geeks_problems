//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr){
      //Code Here
      unordered_set<int> rows, cols;
      vector<long long int> result;
      long long totalZero = (long long)n * n;
      
      for (int i = 0; i < k; i++) {
          int r = arr[i][0], c = arr[i][1];
          if (rows.find(r) == rows.end()) {
              totalZero -= n - cols.size();
              rows.insert(r);
          }
          if (cols.find(c) == cols.end()) {
              totalZero -= n - rows.size();
              cols.insert(c);
          }
          result.push_back(totalZero);
      }
      return result;
  }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> arr(k,vector<int>(2));
        for(int i=0;i<k;i++){
            int x, y;
            cin>>x>>y;
            arr[i][0] = x;
            arr[i][1] = y;
        }
        Solution ob;
        vector<long long int> ans = ob.countZero(n,k,arr);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;    
    
cout << "~" << "\n";
}
    
    return 0;
}


// } Driver Code Ends