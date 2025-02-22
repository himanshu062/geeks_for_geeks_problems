//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // code here
        int maxLeft = left.empty() ? 0 : *max_element(left.begin(), left.end());
        int minRight = right.empty() ? n : *min_element(right.begin(), right.end());
        return max(maxLeft, n - minRight);
    }
};

//{ Driver Code Starts.

int main() {

    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        int n;
        cin >> n;
        cin.ignore();

        string input;
        vector<int> left;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            left.push_back(number);
        }

        string input2;
        vector<int> right;

        // Read the array from input line
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            right.push_back(number2);
        }

        // Solution instance to invoke the function
        Solution ob;
        int lastMoment = ob.getLastMoment(n, left, right);
        cout << lastMoment << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends