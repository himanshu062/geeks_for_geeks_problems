//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<string> camelCase(vector<string> &arr, string &pat) {
        // code here
        vector<string> result;

        for (string word : arr) {
            string pattern = "";
            for (char ch : word) {
                if (isupper(ch)) {
                    pattern += ch;
                }
            }

            if (pattern.find(pat) == 0) {
                result.push_back(word);
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
    cin.ignore(); // Clear the buffer after reading t
    while (t--) {
        string input;
        vector<string> arr;

        // Read the line of words
        getline(cin, input);
        stringstream ss(input);
        string word;
        while (ss >> word) {
            arr.push_back(word);
        }

        string pat;
        cin >> pat;
        cin.ignore(); // Clear the buffer after reading pat

        // Create an instance of the Solution class
        Solution ob;
        vector<string> ans = ob.camelCase(arr, pat);
        if (ans.empty()) {
            cout << "[]\n";
        } else {
            // Sort results before printing
            sort(ans.begin(), ans.end());
            for (const auto& u : ans)
                cout << u << " ";
            cout << "\n";
        }
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends