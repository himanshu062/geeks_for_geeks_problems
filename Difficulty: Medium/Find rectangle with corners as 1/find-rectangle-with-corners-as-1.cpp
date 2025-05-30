//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
#include <unordered_map>
#include <unordered_set>
using namespace std; 

// } Driver Code Ends

//User function Template for C++

class Solution{
    public:
    bool ValidCorner(const vector<vector<int> >& matrix)
    {
        // Your code goes here
        int n = matrix.size(), m = matrix[0].size();
        unordered_map<int, unordered_set<int>> colPairs;
        
        for (int i = 0; i < n; i++) {
            for (int c1 = 0; c1 < m; c1++) {
                if (matrix[i][c1] == 1) {
                    for (int c2 = c1 + 1; c2 < m; c2++) {
                        if (matrix[i][c2] == 1) {
                            if (colPairs[c1].count(c2)) return true;
                            colPairs[c1].insert(c2);
                        }
                    }
                }
            }
        }
        return false;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int row, col;
        cin>> row>> col;

        vector<vector<int> > matrix(row);
            
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        Solution ob;
        if (ob.ValidCorner(matrix)) 
            cout << "Yes\n"; 
        else
            cout << "No\n"; 
    
cout << "~" << "\n";
}

    return 0;
} 



// } Driver Code Ends