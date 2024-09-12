//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return Largest Number

class Solution
{
    public:
    //Function to return the largest possible number of n digits
    //with sum equal to given sum.
    string largestNumber(int n, int s)
    {
        // Your code here
        if (s == 0) 
            return (n == 1) ? "0" : string(n, '0');
        if (s > 9 * n) return "-1";

        string result = "";

        for (int i = 0; i < n; i++) {
            if (s >= 9) {
                result += '9';  
                s -= 9;
            } 
            else {
                result += to_string(s); 
                s = 0;
            }
        }
        return result;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin>>t;

	while(t--)
	{
	    //taking n and sum
		int n,sum;
		cin>>n>>sum;
		
        Solution obj;
        //function call
		cout<<obj.largestNumber(n, sum)<<endl;
	}
	return 0;
}
// } Driver Code Ends