//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
    public:
    //Function to find most frequent word in an array of strings.
    string mostFrequentWord(string arr[], int n) 
    {
        // code here
        unordered_map<string, pair<int, int>> freq; 
        for (int i = 0; i < n; i++) {
            if (freq.find(arr[i]) == freq.end()) {
                freq[arr[i]] = {1, i}; 
            } else {
                freq[arr[i]].first++;
            }
        }

        string result = "";
        int maxFrequency = 0, lastIndex = -1;
        for (auto &it : freq) {
            int count = it.second.first;
            int index = it.second.second;
            
            if (count > maxFrequency || 
                (count == maxFrequency && index > lastIndex)) {
                maxFrequency = count;
                lastIndex = index;
                result = it.first;
            }
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

        string arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.mostFrequentWord(arr, n) << endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends