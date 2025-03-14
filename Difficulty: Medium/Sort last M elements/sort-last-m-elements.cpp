//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    void sortLastMelements(vector<int>&nums, int n, int m) {
    	// Code here
    	sort(nums.begin() + n, nums.end());
        inplace_merge(nums.begin(), nums.begin() + n, nums.end());
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<int>nums(n+m);
		for(auto &i: nums)
			cin >> i;
		Solution obj;
		obj.sortLastMelements(nums, n, m);
		for(auto i: nums)
			cout << i << " ";
		cout << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends