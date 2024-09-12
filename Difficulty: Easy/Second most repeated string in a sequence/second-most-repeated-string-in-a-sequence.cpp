//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        //code here.
        unordered_map<string, int> freqMap;
        
        for (int i = 0; i < n; ++i) {
            freqMap[arr[i]]++;
        }
        
        int firstMax = INT_MIN, secondMax = INT_MIN;
        string firstFreq = "", secondFreq = "";
        
        for (auto it : freqMap) {
            if (it.second > firstMax) {
                secondMax = firstMax;
                secondFreq = firstFreq;
                firstMax = it.second;
                firstFreq = it.first;
            } else if (it.second > secondMax && it.second < firstMax) {
                secondMax = it.second;
                secondFreq = it.first;
            }
        }
        
        return secondFreq;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends