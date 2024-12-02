//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
 
class Solution
{
    public:
    // Function for finding maximum AND value.
    int checkBit(int pattern, int arr[], int N) {
        int count = 0;
        for (int i = 0; i < N; i++) {
            if ((pattern & arr[i]) == pattern) {
                count++;
            }
        }
        return count;
    }
    
    int maxAND (int arr[], int N) {
        int result = 0;
        for (int bit = 31; bit >= 0; bit--) {
            int candidate = result | (1 << bit);
            if (checkBit(candidate, arr, N) >= 2) {
                result = candidate;
            }
        }
        return result;
    }
};

//{ Driver Code Starts.
 
// Driver function
int main()
{
    int t;
    cin>>t;//testcases
    while(t--)
    {
        int n;
        cin>>n;//input n
        int arr[n+5],i;
        
        //inserting elements
        for(i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        //calling maxAND() function
        cout <<  obj.maxAND(arr,n)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends