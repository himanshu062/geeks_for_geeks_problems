//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function Template for C++

class Solution{   
public:
    void dfs(vector<vector<int>> &mat, vector<vector<bool>> &visited, int i, int j, int N, int M) {
        visited[i][j] = true;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        for(int d = 0; d < 4; d++) {
            int ni = i + dx[d], nj = j + dy[d];
            if(ni >= 0 && ni < N && nj >= 0 && nj < M && !visited[ni][nj] && mat[ni][nj] >= mat[i][j]) {
                dfs(mat, visited, ni, nj, N, M);
            }
        }
    }
    
    int water_flow(vector<vector<int>> &mat,int N,int M){
        vector<vector<bool>> indian(N, vector<bool>(M, false));
        vector<vector<bool>> arabian(N, vector<bool>(M, false));
        
        for(int i = 0; i < N; i++) {
            dfs(mat, indian, i, 0, N, M);
            dfs(mat, arabian, i, M-1, N, M);
        }
        
        for(int j = 0; j < M; j++) {
            dfs(mat, indian, 0, j, N, M);
            dfs(mat, arabian, N-1, j, N, M);
        }
        
        int count = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(indian[i][j] && arabian[i][j]) count++;
            }
        }
        
        return count;
    }
};




//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>mat[i][j];
            }
        }
        Solution ob;
        cout << ob.water_flow(mat, n, m) << endl;
        
    
cout << "~" << "\n";
}
}


// } Driver Code Ends