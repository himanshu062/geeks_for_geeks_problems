//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  private:
    long long countSubarraysWithSumLessThan(vector<int>& A, int N, long long maxSum) {
        long long count = 0, currentSum = 0;
        int start = 0;
        
        for (int end = 0; end < N; end++) {
            currentSum += A[end];
            while (currentSum > maxSum) {
                currentSum -= A[start];
                start++;
            }
            count += (end - start + 1);
        }
        
        return count;
    }
    
  public:
    long long countSubarray(int N, vector<int> A, long long L, long long R) {
        return countSubarraysWithSumLessThan(A, N, R) - countSubarraysWithSumLessThan(A, N, L - 1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        long long L,R;
        cin>>N>>L>>R;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution obj;
        auto ans = obj.countSubarray(N,A,L,R);
        cout<<ans<<endl;
    
cout << "~" << "\n";
}
}  
// } Driver Code Ends