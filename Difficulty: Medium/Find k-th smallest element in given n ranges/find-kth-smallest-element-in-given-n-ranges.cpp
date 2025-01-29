//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
        //Write your code here
        sort(range.begin(), range.end());
        vector<pair<int, int>> merged;
        
        for (auto& r : range) {
            if (!merged.empty() && merged.back().second >= r[0] - 1) {
                merged.back().second = max(merged.back().second, r[1]);
            } else {
                merged.push_back({r[0], r[1]});
            }
        }
        
        vector<int> ans;
        for (int k : queries) {
            int count = 0, res = -1;
            for (auto& r : merged) {
                int len = r.second - r.first + 1;
                if (count + len >= k) {
                    res = r.first + (k - count - 1);
                    break;
                }
                count += len;
            }
            ans.push_back(res);
        }
        
        return ans;
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
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(n, range, q, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	
cout << "~" << "\n";
}
	return 0;
}

// } Driver Code Ends