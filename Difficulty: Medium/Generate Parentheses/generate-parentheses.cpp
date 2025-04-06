//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends

//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    vector<string> AllParenthesis(int n) 
    {
        vector<string> res;
        generateParenthesis(n, 0, 0, "", res);
        return res;
    }
    
    void generateParenthesis(int n, int open, int close, string curr, vector<string>& res) {
        if(curr.length() == 2*n) {
            res.push_back(curr);
            return;
        }
        
        if(open < n) {
            generateParenthesis(n, open + 1, close, curr + "(", res);
        }
        if(close < open) {
            generateParenthesis(n, open, close + 1, curr + ")", res);
        }
    }
};


//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	
cout << "~" << "\n";
}
	return 0; 
} 

// } Driver Code Ends