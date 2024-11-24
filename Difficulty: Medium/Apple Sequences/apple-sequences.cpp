//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int appleSequences(int n, int m, string arr){
        // code here 
        int left = 0, right = 0, maxLength = 0, orangeCount = 0;
        while (right < n) {
            if (arr[right] == 'O') orangeCount++;
            while (orangeCount > m) {
                if (arr[left] == 'O') orangeCount--;
                left++;
            }
            maxLength = max(maxLength, right - left + 1);
            right++;
        }
        return maxLength;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M;
        cin >> N >> M;
        string arr;
        cin >> arr;
        
        Solution ob;
        cout << ob.appleSequences(N, M, arr) << endl;
    
cout << "~" << "\n";
}
    return 0; 
} 
// } Driver Code Ends