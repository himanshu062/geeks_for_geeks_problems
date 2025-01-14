//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int>prefix(n,0);
        vector<int>suffix(n,0);
        prefix[0] = arr[0];
        suffix[n-1] = arr[n-1];
        
        for(int i=1;i<n;i++)
        { 
            prefix[i] = prefix[i-1] + arr[i];
        }
        
        for(int i=n-2;i>=0;i--)
        { 
            suffix[i] = suffix[i+1] + arr[i];
        }
        
        int index = -1;
        for(int i=0;i<n;i++)
        { 
            if(prefix[i] == suffix[i])
            { 
                index = i;
                break;
            }
        }
        
        return index;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.findEquilibrium(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends