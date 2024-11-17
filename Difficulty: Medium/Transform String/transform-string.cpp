//{ Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int transform(string A, string B) {
        if (A.size() != B.size())
            return -1;

        unordered_map<char, int> freqA, freqB;
        for (char c : A) freqA[c]++;
        for (char c : B) freqB[c]++;
        if (freqA != freqB)
            return -1;

        int n = A.size(), steps = 0;
        int i = n - 1, j = n - 1;

        while (i >= 0 && j >= 0) {
            if (A[i] == B[j]) {
                j--;
            } else {
                steps++;
            }
            i--;
        }

        return steps;
    }
};



//{ Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends