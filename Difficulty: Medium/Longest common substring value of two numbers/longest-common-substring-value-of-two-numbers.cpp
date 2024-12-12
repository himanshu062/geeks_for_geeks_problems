//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
long long int longestCommon (long long int n1, long long int n2);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        long long int n1, n2; cin >> n1 >> n2;

        cout << longestCommon (n1, n2) << endl;
    
cout << "~" << "\n";
}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


long long int longestCommon (long long int N, long long int M)
{
    // your code here
    string binaryN = bitset<64>(N).to_string();
    string binaryM = bitset<64>(M).to_string();

    reverse(binaryN.begin(), binaryN.end());
    reverse(binaryM.begin(), binaryM.end());

    while (!binaryN.empty() && binaryN.back() == '0') binaryN.pop_back();
    while (!binaryM.empty() && binaryM.back() == '0') binaryM.pop_back();

    reverse(binaryN.begin(), binaryN.end());
    reverse(binaryM.begin(), binaryM.end());

    int maxLength = 0, n = binaryN.size(), m = binaryM.size();
    long long maxDecimal = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int length = 0;
            while (i + length < n && j + length < m && binaryN[i + length] == binaryM[j + length]) {
                length++;
            }
            if (length > maxLength) {
                maxLength = length;
                maxDecimal = stoll(binaryN.substr(i, length), nullptr, 2);
            } else if (length == maxLength) {
                maxDecimal = max(maxDecimal, stoll(binaryN.substr(i, length), nullptr, 2));
            }
        }
    }

    return maxDecimal;
}