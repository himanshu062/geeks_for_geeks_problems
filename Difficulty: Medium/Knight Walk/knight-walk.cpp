//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    // Code here
	    vector<vector<bool>> visited(N+1, vector<bool>(N+1, false));
        queue<pair<int, int>> q;
        q.push({KnightPos[0], KnightPos[1]});
        visited[KnightPos[0]][KnightPos[1]] = true;
        
        int steps = 0;
        vector<pair<int, int>> directions = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}};
        
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                pair<int, int> current = q.front();
                q.pop();
                int x = current.first, y = current.second;
                
                if (x == TargetPos[0] && y == TargetPos[1]) return steps;
                
                for (auto dir : directions) {
                    int newX = x + dir.first;
                    int newY = y + dir.second;
                    if (newX > 0 && newY > 0 && newX <= N && newY <= N && !visited[newX][newY]) {
                        visited[newX][newY] = true;
                        q.push({newX, newY});
                    }
                }
            }
            steps++;
        }
        return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends