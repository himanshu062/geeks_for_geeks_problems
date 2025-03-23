//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// Function to print the k numbers with most occurrences

class Solution {
  public:
    // Function to return the sum of frequencies of k numbers
    // with most occurrences in an array.
    int kMostFrequent(vector<int>& arr, int k) {
        // Your code here
        unordered_map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
        }
        
        priority_queue<int> pq;
        for (auto it = freq.begin(); it != freq.end(); ++it) {
            pq.push(it->second);
        }
        
        int sum = 0;
        while (k--) {
            sum += pq.top();
            pq.pop();
        }
        
        return sum;
    }
};


//{ Driver Code Starts.
//   Driver program to test above
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string str, line;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr, arr2;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        getline(cin, line);
        stringstream ss1(line);
        while (ss1 >> num) {
            arr2.push_back(num);
        }
        int k = arr2[0];
        Solution ob;
        cout << ob.kMostFrequent(arr, k) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends