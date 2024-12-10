//{ Driver Code Starts
// C++ Program to count pairs whose sum divisible
// by '4'
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int count4Divisibiles(vector<int>& arr) {
        // Complete the function
        int count[4] = {0}; 
        int result = 0;

        for (int num : arr) {
            count[num % 4]++;
        }
        result += (count[0] * (count[0] - 1)) / 2;
        result += count[1] * count[3];
        result += (count[2] * (count[2] - 1)) / 2;

        return result;
    }
};

//{ Driver Code Starts.
//   Driver code
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
        Solution ob;
        cout << ob.count4Divisibiles(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends