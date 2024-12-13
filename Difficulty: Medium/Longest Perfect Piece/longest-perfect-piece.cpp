//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestPerfectPiece(int arr[], int N) {
        // code here
        multiset<int> window;
        int start = 0, maxLength = 0;
        
        for (int end = 0; end < N; ++end) {
            window.insert(arr[end]);
            
            while (*window.rbegin() - *window.begin() > 1) {
                window.erase(window.find(arr[start]));
                start++;
            }
            
            maxLength = max(maxLength, end - start + 1);
        }
        
        return maxLength;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.longestPerfectPiece(arr,N) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends