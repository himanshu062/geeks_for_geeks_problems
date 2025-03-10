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
    vector<int> getDistinctDifference(int N, vector<int> &A) {
        // code here
        vector<int> left(N, 0), right(N, 0), res(N);
        unordered_set<int> s;
        
        for (int i = 0; i < N; i++) {
            left[i] = s.size();
            s.insert(A[i]);
        }
        
        s.clear();
        for (int i = N - 1; i >= 0; i--) {
            right[i] = s.size();
            s.insert(A[i]);
        }
        
        for (int i = 0; i < N; i++) {
            res[i] = left[i] - right[i];
        }
        
        return res;
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
        
        Solution obj;
        vector<int> res = obj.getDistinctDifference(N, A);
        
        Array::print(res);
        
    
cout << "~" << "\n";
}
}

// } Driver Code Ends