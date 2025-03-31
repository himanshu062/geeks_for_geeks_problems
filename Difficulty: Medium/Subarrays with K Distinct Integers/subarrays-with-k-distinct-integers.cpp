//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  
        private:
    int atMostK(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        int left = 0, count = 0;
        for (int right = 0; right < arr.size(); right++) {
            if (++freq[arr[right]] == 1) k--;
            while (k < 0) {
                if (--freq[arr[left]] == 0) k++;
                left++;
            }
            count += (right - left + 1);
        }
        return count;
    }

  public:
    int exactlyK(vector<int>& arr, int k) {
        return atMostK(arr, k) - atMostK(arr, k - 1);
        
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
        stringstream ss(input);
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution obj;
        cout << obj.exactlyK(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends