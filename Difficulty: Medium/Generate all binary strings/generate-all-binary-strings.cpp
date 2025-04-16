//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function Template for C++

class Solution{
public:
    void helper(int n, string current, vector<string>& result, char last) {
        if (n == 0) {
            result.push_back(current);
            return;
        }
        helper(n - 1, current + '0', result, '0');
        if (last != '1') {
            helper(n - 1, current + '1', result, '1');
        }
    }

    vector<string> generateBinaryStrings(int num){
        vector<string> result;
        helper(num, "", result, '0');
        return result;
    }
};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        
        vector<string> v = obj.generateBinaryStrings(n);
        for(auto it:v) cout<<it<<" ";
        cout << endl;
    
cout << "~" << "\n";
}

    return 0;
}

// } Driver Code Ends