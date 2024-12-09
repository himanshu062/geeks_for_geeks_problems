//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    
    public:
    int transfigure (string A, string B)
    {
    	// Your code goes here
    	if (A.size() != B.size()) return -1;

        vector<int> freq(256, 0);
        for (char ch : A) freq[ch]++;
        for (char ch : B) freq[ch]--;
        
        for (int count : freq) {
            if (count != 0) return -1;
        }

        int n = A.size(), i = n - 1, j = n - 1, operations = 0;

        while (i >= 0) {
            if (A[i] != B[j]) operations++;
            else j--;
            i--;
        }
        return operations;
    }
};

//{ Driver Code Starts.


int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution obj;
        cout << obj.transfigure (A, B) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends