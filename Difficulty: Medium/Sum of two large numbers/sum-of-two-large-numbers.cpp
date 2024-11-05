//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string findSum(string X, string Y) {
        // Your code goes here
        if (X.length() > Y.length()) swap(X, Y);
    string result = "";
    int n1 = X.length(), n2 = Y.length();
    int carry = 0, diff = n2 - n1;

    for (int i = n1 - 1; i >= 0; i--) {
        int sum = ((X[i] - '0') + (Y[i + diff] - '0') + carry);
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    for (int i = n2 - n1 - 1; i >= 0; i--) {
        int sum = ((Y[i] - '0') + carry);
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    if (carry) result.push_back(carry + '0');
    reverse(result.begin(), result.end());

    int pos = result.find_first_not_of('0');
    return pos == string::npos ? "0" : result.substr(pos);
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;
        Solution ob;
        cout << ob.findSum(x, y) << "\n";
    
cout << "~" << "\n";
}

    return 0;
}
// } Driver Code Ends