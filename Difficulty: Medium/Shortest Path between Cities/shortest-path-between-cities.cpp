//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

//User function Template for C++

class Solution{   
public:
    int shortestPath( int x, int y){ 
        // code here 
        int steps = 0;
        while (x != y) {
            if (x > y) x /= 2;
            else y /= 2;
            steps++;
        }
        return steps;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<< ob.shortestPath(x,y) << endl;
    
cout << "~" << "\n";
}
    return 0; 
} 
// } Driver Code Ends