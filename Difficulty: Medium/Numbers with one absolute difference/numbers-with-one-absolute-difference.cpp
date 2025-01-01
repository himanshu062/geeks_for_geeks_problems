//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    void dfs(long long num, long long N, vector<long long>& result) {
        if (num > N) return;
        if (num > 9) result.push_back(num);  
        int last_digit = num % 10;
        if (last_digit > 0) 
            dfs(num * 10 + last_digit - 1, N, result);  
        if (last_digit < 9)
            dfs(num * 10 + last_digit + 1, N, result);  
    }

    vector<long long> absDifOne(long long N) {
        vector<long long> result;
        for (int i = 1; i <= 9; ++i) {
            dfs(i, N, result);
        }
        sort(result.begin(), result.end());
        return result;
    }

};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
        {
            long long n;
            cin>>n;
            Solution ob;
            vector<long long> res = ob.absDifOne(n);
            for(int i = 0;i<res.size();i++)
                cout<<res[i]<<" ";
            if(res.size()==0)
                cout<<-1;
            cout<<endl;    
        
cout << "~" << "\n";
}
}

// } Driver Code Ends