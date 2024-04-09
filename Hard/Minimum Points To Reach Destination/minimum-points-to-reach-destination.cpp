//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minPoints(int m, int n, vector<vector<int>> arr) 
	{ 
	    // Your code goes here
	     int res[m][n];
	    res[m-1][n-1] = arr[m-1][n-1] > 0? 1: abs(arr[m-1][n-1]) + 1; 
	    for (int i = m-2; i >= 0; i--) 
	         res[i][n-1] = max(res[i+1][n-1] - arr[i][n-1], 1); 
	    for (int j = n-2; j >= 0; j--) 
	         res[m-1][j] = max(res[m-1][j+1] - arr[m-1][j], 1); 
	    for (int i=m-2; i>=0; i--) 
	    { 
	        for (int j=n-2; j>=0; j--) 
	        {  
	            res[i][j] = max(min(res[i+1][j], res[i][j+1])-arr[i][j], 1); 
	        } 
	     } 
	     return res[0][0]; 
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;

        vector<vector<int>> a(m, vector<int>(n));

        for(int i = 0; i < m; i++)
        	for(int j = 0; j < n; j++)
        		cin >> a[i][j];

        

	    Solution ob;
	    cout << ob.minPoints(m,n,a) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends