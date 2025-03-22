//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{

    public:
    vector<vector<int> > findDistance(vector<vector<char> >& matrix, int M, int N) 
    { 
        // Your code goes here
        vector<vector<int>> dist(M, vector<int>(N, -1));
        queue<pair<int, int>> q;
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (matrix[i][j] == 'B') {
                    dist[i][j] = 0;
                    q.push({i, j});
                } else if (matrix[i][j] == 'W') {
                    dist[i][j] = -1;
                }
            }
        }
        
        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            int x = curr.first, y = curr.second;
            
            for (auto& dir : directions) {
                int nx = x + dir[0], ny = y + dir[1];
                
                if (nx >= 0 && nx < M && ny >= 0 && ny < N && matrix[nx][ny] == 'O' && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        
        return dist;
    } 
};


//{ Driver Code Starts.


int main()
{

    int t;
    cin >> t;
    while(t--)
    {
    	int M,N;
        cin>>M;
        cin>>N;

        vector<vector<char> > matrix(M);
        for(int i=0; i<M; ++i)
        {
            matrix[i].resize(N);
            for (int j = 0; j < N; ++j)
                cin>>matrix[i][j];
        }

        vector<vector<int> >result;
        Solution obj;
        result = obj.findDistance(matrix, M,N); 
        for(int i=0; i<M; ++i)
        {
            for (int j = 0; j < N; ++j)
                cout<<result[i][j]<<" ";
            cout<<"\n";
        }
    
cout << "~" << "\n";
}

    return 0;
}
// } Driver Code Ends