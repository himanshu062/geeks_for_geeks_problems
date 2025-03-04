//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Back-end complete function Template for C++

class Solution {
  public:
    vector<int> commonElements(vector<int> &a, vector<int> &b) {
        // Your code here
        unordered_map<int, int> freq;
        vector<int> result;
        
        for (int num : a) freq[num]++;
        
        for (int num : b) {
            if (freq[num] > 0) {
                result.push_back(num);
                freq[num]--;
            }
        }
        
        sort(result.begin(), result.end());
        return result;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> a;
        int num;
        while (ss >> num) {
            a.push_back(num);
        }
        string str1;
        getline(cin, str1);

        stringstream ss1(str1);
        vector<int> b;
        int num1;
        while (ss1 >> num1) {
            b.push_back(num1);
        }
        Solution ob;
        vector<int> result;
        result = ob.commonElements(a, b);
        for (auto i : result) {
            cout << i << " ";
        }
        cout << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends