//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
	public:
	double findProb(int N,int start_x, int start_y, int steps)
	{
	    // Code here
	    vector<vector<vector<double>>> dp(steps + 1, vector<vector<double>>(N, vector<double>(N, 0)));
	    dp[0][start_x][start_y] = 1.0;
	    int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
	    int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

	    for (int k = 1; k <= steps; k++) {
	        for (int i = 0; i < N; i++) {
	            for (int j = 0; j < N; j++) {
	                for (int d = 0; d < 8; d++) {
	                    int ni = i + dx[d], nj = j + dy[d];
	                    if (ni >= 0 && nj >= 0 && ni < N && nj < N)
	                        dp[k][ni][nj] += dp[k - 1][i][j] / 8.0;
	                }
	            }
	        }
	    }

	    double prob = 0.0;
	    for (int i = 0; i < N; i++)
	        for (int j = 0; j < N; j++)
	            prob += dp[steps][i][j];

	    return prob;
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N, start_x, start_y, steps;
		cin >> N >> start_x >> start_y >> steps;
		Solution ob;
		double ans = ob.findProb(N, start_x, start_y, steps);
		cout << fixed << setprecision(6) << ans <<"\n";
	
cout << "~" << "\n";
}  
	return 0;
}
// } Driver Code Ends