//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int maxLength(vector<int> &arr,int n){
           //code here
           int pos_len = 0, neg_len = 0, max_len = 0;
            
            for (int i = 0; i < n; i++) {
                if (arr[i] > 0) {
                    pos_len++;
                    neg_len = neg_len > 0 ? neg_len + 1 : 0;
                } else if (arr[i] < 0) {
                    int temp = pos_len;
                    pos_len = neg_len > 0 ? neg_len + 1 : 0;
                    neg_len = temp + 1;
                } else {
                    pos_len = neg_len = 0;
                }
                max_len = max(max_len, pos_len);
            }
            
            return max_len;
        }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends