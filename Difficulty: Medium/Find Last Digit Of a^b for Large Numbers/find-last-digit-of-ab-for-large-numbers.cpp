//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int getLastDigit(string a, string b) {
        // code here
        if (b == "0") return 1; 
        int base = a.back() - '0'; 
        int len_b = b.length();
        int exp = 0;
        for (int i = 0; i < len_b; i++) {
            exp = (exp * 10 + (b[i] - '0')) % 4;
        }
        if (exp == 0) exp = 4; 
        int result = pow(base, exp);
        return result % 10; 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string a,b;
        
        cin>>a>>b;

        Solution ob;
        cout << ob.getLastDigit(a,b) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends