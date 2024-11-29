//{ Driver Code Starts
// C++ program to find union of
// two sorted arrays
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> scores(vector<int>& arr1, vector<int>& arr2) {
        // Your code goes here
        int scoreA = 0, scoreB = 0;
        for (int i = 0; i < 3; ++i) {
            if (arr1[i] > arr2[i]) scoreA++;
            else if (arr1[i] < arr2[i]) scoreB++;
        }
        return {scoreA, scoreB};
    }
};

//{ Driver Code Starts.
/* Driver program to test above function */
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {

        vector<int> arr1, arr2;
        string input1;
        getline(cin, input1);
        stringstream ss(input1);
        int number1;
        while (ss >> number1) {
            arr1.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream sss(input2);
        int number2;
        while (sss >> number2) {
            arr2.push_back(number2);
        }
        Solution ob;
        // Function calling
        vector<int> v;
        v = ob.scores(arr1, arr2);

        for (int i = 0; i < v.size(); i++)
            cout << v[i] << " ";

        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends