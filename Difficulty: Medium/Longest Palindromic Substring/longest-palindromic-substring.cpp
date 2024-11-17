//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string longestPalindrome(string S){
        // code here 
        int n = S.size();
        int start = 0, maxLength = 1;

        for (int i = 0; i < n; i++) {
            int low = i - 1, high = i + 1;

            while (high < n && S[high] == S[i]) high++;
            while (low >= 0 && S[low] == S[i]) low--;
            while (low >= 0 && high < n && S[low] == S[high]) {
                low--;
                high++;
            }

            int length = high - low - 1;
            if (length > maxLength) {
                maxLength = length;
                start = low + 1;
            }
        }

        return S.substr(start, maxLength);
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends