//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int findPairs(vector<int>& arr) {
        // code here.
        unordered_map<int, pair<int, int>> productMap;
        
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int product = arr[i] * arr[j];
                if (productMap.find(product) != productMap.end()) {
                    pair<int, int> prevPair = productMap[product];
                    if (prevPair.first != i && prevPair.first != j && prevPair.second != i && prevPair.second != j) {
                        return 1;  
                    }
                }
                productMap[product] = {i, j};
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.findPairs(arr) << endl;
    }
}

// } Driver Code Ends