//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        //Your code here
        unordered_map<int, int> prefixSumCount;
        int prefixSum = 0;
        long long int count = 0;

        prefixSumCount[0] = 1;

        for (int i = 0; i < n; i++) {
            prefixSum += (arr[i] == 0) ? -1 : 1;
            if (prefixSumCount.find(prefixSum) != prefixSumCount.end()) {
                count += prefixSumCount[prefixSum];
            }
            prefixSumCount[prefixSum]++;
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
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution obj;
	cout<< obj.countSubarrWithEqualZeroAndOne(arr, n)<<"\n";
	
cout << "~" << "\n";
}
	return 0;
}

// } Driver Code Ends