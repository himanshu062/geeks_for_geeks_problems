//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template for C++ solution

class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
        // Your code here
        vector<long long> result(n, -1);
        stack<long long> st;
        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= arr[i % n]) {
                st.pop();
            }
            if (i < n) {
                if (!st.empty()) {
                    result[i] = st.top();
                }
            }
            st.push(arr[i % n]);
        }
        return result;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution ob;
        
        vector <long long> res = ob.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    
cout << "~" << "\n";
}
	return 0;
}

// } Driver Code Ends