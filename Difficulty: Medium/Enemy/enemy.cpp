//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++

class Solution
{
    public:
        int largestArea(int n,int m,int k,vector<vector<int>> &enemy)
        {
            //  code here
            if (k == 0) return n * m;

        vector<int> rows, cols;
        for (auto &e : enemy) {
            rows.push_back(e[0]);
            cols.push_back(e[1]);
        }

        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());

        int maxRowGap = max(rows[0] - 1, n - rows.back());
        int maxColGap = max(cols[0] - 1, m - cols.back());

        for (int i = 1; i < k; i++) {
            maxRowGap = max(maxRowGap, rows[i] - rows[i - 1] - 1);
            maxColGap = max(maxColGap, cols[i] - cols[i - 1] - 1);
        }

        return maxRowGap * maxColGap;
        }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int k;
        cin>>k;
        vector<vector<int>> e(k,vector<int>(2));
        for(int i=0;i<k;i++)
            cin>>e[i][0]>>e[i][1];
        Solution a;
        cout<<a.largestArea(n,m,k,e)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends