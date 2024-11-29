//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int N, vector<int> Edge)
  {
      // code here
      vector<int> weight(N, 0);
        for (int i = 0; i < N; ++i) {
            if (Edge[i] != -1) {
                weight[Edge[i]] += i;
            }
        }
        int maxWeight = 0, maxIndex = 0;
        for (int i = 0; i < N; ++i) {
            if (weight[i] > maxWeight || (weight[i] == maxWeight && i > maxIndex)) {
                maxWeight = weight[i];
                maxIndex = i;
            }
        }
        return maxIndex;
  }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   
cout << "~" << "\n";
}
   return 0;
}
// } Driver Code Ends