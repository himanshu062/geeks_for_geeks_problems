//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:

    int steppingNumbers(int n, int m)
    {
        // Code Here
        queue<int> q;
        int count = 0;
        
        if (n == 0) count++;
        
        for (int i = 1; i <= 9; i++) q.push(i);

        while (!q.empty()) {
            int num = q.front();
            q.pop();

            if (num >= n && num <= m) count++;

            if (num > m) continue;

            int lastDigit = num % 10;
            if (lastDigit > 0) q.push(num * 10 + (lastDigit - 1));
            if (lastDigit < 9) q.push(num * 10 + (lastDigit + 1));
        }
        
        return count;
    }
};


//{ Driver Code Starts.

int main()
{
    
    int t;
    cin>>t;
    while(t--)
    {
        Solution obj;
        int n, m;
        cin>>n>>m;
        cout << obj.steppingNumbers(n,m) << endl;
    
cout << "~" << "\n";
}
	return 0;
}


// } Driver Code Ends