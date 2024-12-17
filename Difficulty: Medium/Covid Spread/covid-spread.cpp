//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int helpaterp(vector<vector<int>> hospital)
    {
        //code here
        int r = hospital.size(), c = hospital[0].size();
        queue<pair<int, int>> q;
        int total_uninfected = 0;

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (hospital[i][j] == 2) {
                    q.push({i, j});
                } else if (hospital[i][j] == 1) {
                    total_uninfected++;
                }
            }
        }

        if (total_uninfected == 0) return 0;

        int time = 0;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            int size = q.size();
            bool infected = false;

            for (int i = 0; i < size; ++i) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for (auto dir : directions) {
                    int nx = x + dir.first, ny = y + dir.second;
                    if (nx >= 0 && nx < r && ny >= 0 && ny < c && hospital[nx][ny] == 1) {
                        hospital[nx][ny] = 2;
                        q.push({nx, ny});
                        infected = true;
                        total_uninfected--;
                    }
                }
            }

            if (infected) time++;
        }

        return total_uninfected == 0 ? time : -1;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends