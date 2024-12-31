//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool bpm(vector<vector<int>>& G, int u, vector<bool>& visited, vector<int>& match, int n) {
        for (int v = 0; v < n; v++) {
            if (G[u][v] && !visited[v]) {
                visited[v] = true;
                if (match[v] == -1 || bpm(G, match[v], visited, match, n)) {
                    match[v] = u;
                    return true;
                }
            }
        }
        return false;
    }

    int maximumMatch(vector<vector<int>>& G) {
        int m = G.size(), n = G[0].size();
        vector<int> match(n, -1);
        int result = 0;

        for (int u = 0; u < m; u++) {
            vector<bool> visited(n, false);
            if (bpm(G, u, visited, match, n))
                result++;
        }

        return result;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int m, n;
		cin >> m >> n;
		vector<vector<int>>G(m, vector<int>(n, 0));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				cin >> G[i][j];
		}
		Solution obj;
		int ans = obj.maximumMatch(G);
		cout << ans << "\n";    
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends