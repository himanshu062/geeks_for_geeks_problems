//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function Template for C++

class Solution{
public:
    long long findNumber(long long N){
        // Code here
        long long res = 0, place = 1;
        vector<int> odd_digits = {1, 3, 5, 7, 9};
        while (N > 0) {
            res += odd_digits[(N - 1) % 5] * place;
            N = (N - 1) / 5;
            place *= 10;
        }
        return res;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long N;
        cin>>N;
        Solution ob;
        cout<<ob.findNumber(N)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends