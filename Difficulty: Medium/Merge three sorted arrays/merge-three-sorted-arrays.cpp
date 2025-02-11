//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std; 


void printVector(const vector<int>& a) 
{ 
    for (auto e : a) { 
        cout << e << " "; 
    }
    cout<<endl;
} 

// } Driver Code Ends
class Solution{
  public:
    // A, B, and C: input sorted arrays
    //Function to merge three sorted vectors or arrays 
    //into a single vector or array.
    vector<int> mergeThree(vector<int>& A, vector<int>& B, vector<int>& C) 
    { 
        //Your code here
        vector<int> result;
        int i = 0, j = 0, k = 0;
        int n = A.size(), m = B.size(), p = C.size();
        
        while (i < n || j < m || k < p) {
            int minVal = INT_MAX;
            if (i < n) minVal = min(minVal, A[i]);
            if (j < m) minVal = min(minVal, B[j]);
            if (k < p) minVal = min(minVal, C[k]);
            
            if (i < n && A[i] == minVal) result.push_back(A[i++]);
            else if (j < m && B[j] == minVal) result.push_back(B[j++]);
            else if (k < p && C[k] == minVal) result.push_back(C[k++]);
        }
        
        return result;
    } 

};

//{ Driver Code Starts.

int main() 
{ 


    int t;
    cin>>t;
    while(t--){
    int n,m,o;
    cin>>n>>m>>o;
    vector<int> A,B,C;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        A.push_back(x);
    }
    
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        B.push_back(x);
    }
    
    for(int i=0;i<o;i++){
        int x;
        cin>>x;
        C.push_back(x);
    }

    Solution obj;
    vector<int>ans = obj.mergeThree(A, B, C);
    for(auto i: ans)cout << i << " ";
    cout << "\n";
    // obj.printVector(mergeThree(A, B, C)); 
    
    
cout << "~" << "\n";
}
   
    return 0; 
} 

// } Driver Code Ends