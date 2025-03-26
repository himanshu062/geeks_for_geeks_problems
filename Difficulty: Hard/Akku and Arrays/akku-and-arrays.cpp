//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends



class Solution {
public:
  vector<int>solveQueries(vector<int>nums, vector<vector<int>>Queries){
      // Code here
      vector<int> result;
        
        for (auto& q : Queries) {
            if (q[0] == 1) {
                nums[q[1] - 1] = q[2]; // Update operation (1-based index to 0-based)
            } else {
                int l = q[1] - 1, r = q[2] - 1;
                bool increasing = true, decreasing = true;
                
                for (int i = l; i < r; i++) {
                    if (nums[i] < nums[i + 1]) decreasing = false;
                    if (nums[i] > nums[i + 1]) increasing = false;
                }
                
                if (increasing && decreasing) result.push_back(-1);
                else if (increasing) result.push_back(0);
                else if (decreasing) result.push_back(1);
                else result.push_back(-1);
            }
        }
        
        return result;
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
		int q;
		cin >> q;
		vector<vector<int>>Queries;
		for(int i = 0; i < q; i++){
			int x, y, z;
			cin >> x >> y >> z;
			Queries.push_back({x,y,z});
		}
		Solution obj;
		vector<int>ans = obj.solveQueries(nums, Queries);
		for(auto i: ans)cout << i << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends