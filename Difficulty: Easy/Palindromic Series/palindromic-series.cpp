//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to check if the given number is a pallan number or not
class Solution {
  public:
    bool pallan(int n) {
        // Write Code Here
        string digits = to_string(n);
        string base_str = "";
        for (char digit : digits) {
            base_str += (char)('a' + (digit - '0'));
        }
        int sum_of_digits = 0;
        for (char digit : digits) {
            sum_of_digits += (digit - '0');
        }
        string result = "";
        while (result.size() < sum_of_digits) {
            result += base_str;
        }
        result = result.substr(0, sum_of_digits);
        int len = result.size();
        for (int i = 0; i < len / 2; i++) {
            if (result[i] != result[len - i - 1]) {
                return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;

        if (ob.pallan(n))
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends