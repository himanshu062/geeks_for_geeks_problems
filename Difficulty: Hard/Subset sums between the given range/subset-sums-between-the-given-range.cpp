//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++

class Solution{
    public:
    long long int countSubsets(vector<int>&arr, int n, int l, int r){
        //Write your code here
        auto computeSums = [](vector<int>& nums) {
            vector<int> sums;
            int size = nums.size();
            for (int mask = 0; mask < (1 << size); ++mask) {
                int sum = 0;
                for (int i = 0; i < size; ++i) {
                    if (mask & (1 << i)) sum += nums[i];
                }
                sums.push_back(sum);
            }
            return sums;
        };

        int mid = n / 2;
        vector<int> left(arr.begin(), arr.begin() + mid);
        vector<int> right(arr.begin() + mid, arr.end());

        vector<int> leftSums = computeSums(left);
        vector<int> rightSums = computeSums(right);

        sort(rightSums.begin(), rightSums.end());

        long long count = 0;
        for (int sum : leftSums) {
            int lower = l - sum;
            int upper = r - sum;

            count += upper_bound(rightSums.begin(), rightSums.end(), upper) - 
                     lower_bound(rightSums.begin(), rightSums.end(), lower);
        }

        return count;
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
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    int l, r;
	    cin >> l >> r;
	    Solution ob;
	    long long int ans = ob.countSubsets(arr, n, l, r);
	    cout << ans<<endl;
	
cout << "~" << "\n";
}
	return 0;
}

// } Driver Code Ends