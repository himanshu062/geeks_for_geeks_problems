//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int ZigZagMaxLength(vector<int>&nums){
		    // Code here
		    if (nums.size() < 2) return nums.size();
		    
		    int inc = 1, dec = 1;
		    
		    for (int i = 1; i < nums.size(); i++) {
		        if (nums[i] > nums[i - 1]) {
		            inc = dec + 1;
		        } else if (nums[i] < nums[i - 1]) {
		            dec = inc + 1;
		        }
		    }
		    
		    return max(inc, dec);
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
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.ZigZagMaxLength(nums);
		cout << ans << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends