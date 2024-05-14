//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	long factorial(long n){
	    if(n==0) return 1;
	    return n*factorial(n-1);
	}
	vector<int> FactDigit(int N)
	{
	    // Code here
	    vector<int> ans;
	    while(N != 0){
	        for(int i=9;i>=0;i--){
	            if(N >= factorial(i)){
	                ans.push_back(i);
	                N -= factorial(i);
	                break;
	            }
	        }
	    }
	    sort(ans.begin(), ans.end());
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.FactDigit(N);
		for(auto i: ans)
			cout << i;
		cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends