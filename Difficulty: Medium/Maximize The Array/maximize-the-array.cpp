//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> maximizeArray(int arr1[], int arr2[], int n) {
            // code here 
            set<int> uniqueElements;
        vector<int> result;
        
        for (int i = n - 1; i >= 0; i--) 
            uniqueElements.insert(arr2[i]);
        
        for (int i = n - 1; i >= 0; i--) 
            uniqueElements.insert(arr1[i]);
        
        while (uniqueElements.size() > n) 
            uniqueElements.erase(*uniqueElements.begin());
        
        vector<int> temp;
        
        for (int i = 0; i < n; i++) 
            if (uniqueElements.count(arr2[i])) {
                temp.push_back(arr2[i]);
                uniqueElements.erase(arr2[i]);
            }
        
        for (int i = 0; i < n; i++) 
            if (uniqueElements.count(arr1[i])) {
                temp.push_back(arr1[i]);
                uniqueElements.erase(arr1[i]);
            }

        return temp;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr1[n], arr2[n];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        auto ans = ob.maximizeArray(arr1, arr2, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends