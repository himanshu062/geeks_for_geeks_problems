//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int findMaxValue(vector<vector<int>>&mat, int N)
    {
        //Write your code here  
        vector<vector<int>> maxMat(N, vector<int>(N, 0));
        maxMat[N-1][N-1] = mat[N-1][N-1];
        
        for (int i = N-2; i >= 0; i--) {
            maxMat[i][N-1] = max(mat[i][N-1], maxMat[i+1][N-1]);
            maxMat[N-1][i] = max(mat[N-1][i], maxMat[N-1][i+1]);
        }
        
        int maxValue = INT_MIN;
        for (int i = N-2; i >= 0; i--) {
            for (int j = N-2; j >= 0; j--) {
                maxValue = max(maxValue, maxMat[i+1][j+1] - mat[i][j]);
                maxMat[i][j] = max(mat[i][j], max(maxMat[i+1][j], maxMat[i][j+1]));
            }
        }
        
        return maxValue;
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
	    vector<vector<int>>mat(n,vector<int>(n, 0));
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < n; j++){
	            cin >> mat[i][j];
	        }
	    }
	    Solution ob;
	    int ans = ob.findMaxValue(mat, n);
	    cout << ans <<endl;
	
cout << "~" << "\n";
}
	return 0;
}

// } Driver Code Ends