//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool searchEle(vector<int>& arr, int x) {
        return find(arr.begin(), arr.end(), x) != arr.end();
    }

    void insertEle(vector<int>& arr, int y, int yi) {
        arr.insert(arr.begin() + yi, y);
    }

    void deleteEle(vector<int>& arr, int z) {
        auto it = find(arr.begin(), arr.end(), z);
        if (it != arr.end()) {
            arr.erase(it);
        }
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr;

        string input;
        getline(cin, input);
        stringstream s1(input);
        int num;
        while (s1 >> num) {
            arr.push_back(num);
        }
        vector<int> temp = arr;
        int x, y, yi, z;
        cin >> x >> y >> yi >> z;
        getline(cin, input);
        Solution obj;
        bool b = obj.searchEle(arr, x);
        if (b)
            cout << "true ";
        else
            cout << "false ";

        obj.insertEle(arr, y, yi);
        temp.insert(temp.begin() + yi, y);
        if (arr == temp)
            cout << "true ";
        else
            cout << "false ";

        obj.deleteEle(arr, z);
        auto it = find(temp.begin(), temp.end(), z);

        if (it != temp.end()) {
            temp.erase(it);
        }
        if (arr == temp)
            cout << "true \n";
        else
            cout << "false \n";
        cout << "~" << endl;
    }
}
// } Driver Code Ends