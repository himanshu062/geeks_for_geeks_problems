//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string S)
	{
	    // Your code goes here
	    int n = S.length();
        int max_diff = INT_MIN, current_diff = 0;
        for (int i = 0; i < n; i++) {
            if (S[i] == '0') 
                current_diff++;
            else 
                current_diff--;
            if (current_diff > max_diff) 
                max_diff = current_diff;
            if (current_diff < 0) 
                current_diff = 0;
            
        }
        return (max_diff > 0) ? max_diff : -1;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	
cout << "~" << "\n";
}

    return 0;
}

// } Driver Code Ends