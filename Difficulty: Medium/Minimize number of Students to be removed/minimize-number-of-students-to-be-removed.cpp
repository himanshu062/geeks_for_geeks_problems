//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int removeStudents(int H[], int N) {
        // code here
        vector<int> lis;
        for (int i = 0; i < N; ++i) {
            auto it = lower_bound(lis.begin(), lis.end(), H[i]);
            if (it == lis.end()) lis.push_back(H[i]);
            else *it = H[i];
        }
        return N - lis.size();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends