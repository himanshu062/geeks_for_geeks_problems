//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void generateSubarrays(vector<int>& arr, int start, vector<vector<int>>& result) {
        for (int end = start; end < arr.size(); end++) {
            vector<int> subarray(arr.begin() + start, arr.begin() + end + 1);
            result.push_back(subarray);
        }
    }

    vector<vector<int>> getSubArrays(vector<int>& arr) {
        vector<vector<int>> result;
        for (int start = 0; start < arr.size(); start++) {
            generateSubarrays(arr, start, result);
        }
        return result;
    }
};

//{ Driver Code Starts.

int main() {

    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        vector<vector<int> > result = ob.getSubArrays(arr);
        int c1 = 0;
        int c2 = 0;
        cout << "[";
        for (const auto& subarray : result) {
            cout << "[";
            c2 = 0;
            for (int num : subarray) {
                c2++;
                if (c2 != subarray.size())
                    cout << num << ",";
                else
                    cout << num << "";
            }
            c1++;
            if (c1 != result.size())
                cout << "], ";
            else
                cout << "]";
        }
        cout << "]" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends