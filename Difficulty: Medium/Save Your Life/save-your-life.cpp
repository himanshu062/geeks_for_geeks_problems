//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
          // code here 
          unordered_map<char, int> asciiMap;
        for (char c = 'a'; c <= 'z'; c++) asciiMap[c] = c;
        for (char c = 'A'; c <= 'Z'; c++) asciiMap[c] = c;
        
        for (int i = 0; i < n; i++) {
            asciiMap[x[i]] = b[i];
        }
        
        int maxSum = INT_MIN, currSum = 0, start = 0, maxStart = 0, maxEnd = 0;
        
        for (int i = 0; i < w.size(); i++) {
            currSum += asciiMap[w[i]];
            if (currSum > maxSum) {
                maxSum = currSum;
                maxStart = start;
                maxEnd = i;
            }
            if (currSum < 0) {
                currSum = 0;
                start = i + 1;
            }
        }
        
        return w.substr(maxStart, maxEnd - maxStart + 1);
      }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    
cout << "~" << "\n";
}
    return 0; 
}
// } Driver Code Ends