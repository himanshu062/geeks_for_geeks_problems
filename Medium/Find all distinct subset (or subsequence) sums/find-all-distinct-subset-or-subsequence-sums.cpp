//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	vector<int> DistinctSum(vector<int>nums){
	    // Code here
	    set<int> st;
	    st.insert(0);
	    for(auto num : nums){
	        vector<int> v;
	        for(auto i : st) v.push_back(i + num);
	        for(auto vv : v) st.insert(vv);
	    }
	    nums.clear();
	    for(auto it : st) nums.push_back(it);
	    return nums;

	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int> ans = obj.DistinctSum(nums);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}

// } Driver Code Ends