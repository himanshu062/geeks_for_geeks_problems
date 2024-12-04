//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    string oneDigit(int n) {
        vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        return ones[n];
    }

    string twoDigits(int n) {
        vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        vector<string> belowTwenty = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        if (n < 10) return oneDigit(n);
        else if (n < 20) return belowTwenty[n - 10];
        else return tens[n / 10] + (n % 10 ? " " + oneDigit(n % 10) : "");
    }

    string threeDigits(int n) {
        if (n < 100) return twoDigits(n);
        return oneDigit(n / 100) + " Hundred" + (n % 100 ? " " + twoDigits(n % 100) : "");
    }

    string convertToWords(int n) {
        if (n == 0) return "Zero";

        vector<string> scales = {"", "Thousand", "Million", "Billion"};
        string result = "";
        int scaleIdx = 0;

        while (n > 0) {
            int part = n % 1000;
            if (part) {
                string partWords = threeDigits(part);
                if (scaleIdx > 0) partWords += " " + scales[scaleIdx];
                result = partWords + (result.empty() ? "" : " ") + result;
            }
            n /= 1000;
            scaleIdx++;
        }
        return result;
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
        auto ans = ob.convertToWords(n);
        cout << "\"" << ans << "\""
             << "\n";
    }
    return 0;
}

// } Driver Code Ends