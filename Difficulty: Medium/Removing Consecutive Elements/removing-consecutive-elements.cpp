//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

vector<int> remove_special_consecutive(vector<int>& arr, int x, int y) {
    // Your code here
    vector<int> result;
    for (int num : arr) {
        if (!result.empty() && (num == x || num == y) && result.back() == num) {
            continue;
        }
        result.push_back(num);
    }
    return result;
}

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        int x, y;
        cin >> x >> y;
        cin.ignore();

        vector<int> result = remove_special_consecutive(arr, x, y);
        for (auto i : result) {
            cout << i << " ";
        }
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends