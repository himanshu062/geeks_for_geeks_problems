//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++


class Solution{
    
    public:
    long long ValidPair(int a[], int n) 
    { 
    	// Your code goes here 
    	sort(a, a + n);
        long long count = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > 0) {
                count += (n - i - 1);
            } else {
                int idx = upper_bound(a + i + 1, a + n, -a[i]) - a;
                count += (n - idx);
            }
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
		int n;
		cin>>n;
		int array[n];
		for (int i = 0; i < n; ++i)
			cin>>array[i];
	    Solution obj;
		cout << obj.ValidPair(array, n) <<"\n";
	
cout << "~" << "\n";
}
	return 0; 
} 


// } Driver Code Ends