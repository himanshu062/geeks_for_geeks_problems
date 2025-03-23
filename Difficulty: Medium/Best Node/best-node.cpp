//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    long long bestNode(int N, vector<int> &A, vector<int> &P) {
        // code here
        unordered_set<int> innerNodes;
        for (int i = 1; i < N; i++) innerNodes.insert(P[i]);

        long long maxVal = LLONG_MIN;
        for (int i = 0; i < N; i++) {
            if (innerNodes.find(i + 1) == innerNodes.end()) {
                long long curr = 0, node = i + 1;
                while (node != -1) {
                    curr = A[node - 1] - curr;
                    maxVal = max(maxVal, curr);
                    node = P[node - 1];
                }
            }
        }
        return maxVal;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        long long res = obj.bestNode(N, A, P);
        
        cout<<res<<endl;
        
    
cout << "~" << "\n";
}
}

// } Driver Code Ends