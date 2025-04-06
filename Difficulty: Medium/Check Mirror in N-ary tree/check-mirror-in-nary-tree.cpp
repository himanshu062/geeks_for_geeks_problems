//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++

class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        // code here
        vector<vector<int>> tree1(n + 1);
        vector<vector<int>> tree2(n + 1);
        
        for(int i = 0; i < 2*e; i += 2) {
            tree1[A[i]].push_back(A[i+1]);
            tree2[B[i]].push_back(B[i+1]);
        }
        
        for(int i = 1; i <= n; i++) {
            vector<int> &child1 = tree1[i];
            vector<int> &child2 = tree2[i];
            
            int size = child1.size();
            if(size != child2.size()) {
                return 0;
            }
            
            for(int j = 0; j < size; j++) {
                if(child1[j] != child2[size-1-j]) {
                    return 0;
                }
            }
        }
        
        return 1;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        
        cin>>n>>e;
        int A[2*e], B[2*e];
        
        for(int i=0; i<2*e; i++)
            cin>>A[i];
            
        for(int i=0; i<2*e; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.checkMirrorTree(n,e,A,B) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends