//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long minTime(int arr[], int n, int k)
    {
         auto canPaintInTime = [&](long long maxTime) {
            int paintersUsed = 1; 
            long long currentSum = 0;
            
            for (int i = 0; i < n; ++i) {
                if (arr[i] > maxTime) return false; 
                if (currentSum + arr[i] > maxTime) {
                    ++paintersUsed;
                    currentSum = arr[i];
                    if (paintersUsed > k) return false; 
                } else {
                    currentSum += arr[i];
                }
            }
            return true;
        };
        
        long long low = *max_element(arr, arr + n); 
        long long high = accumulate(arr, arr + n, 0LL); 
        long long result = high;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            
            if (canPaintInTime(mid)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
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
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends