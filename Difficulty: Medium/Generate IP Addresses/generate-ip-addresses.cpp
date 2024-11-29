//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    vector<string> genIp(string &s) {
        // Your code here
        vector<string> result;
        int n = s.size();

        if (n < 4 || n > 12) return result;

        for (int i = 1; i < n && i < 4; i++) {
            for (int j = i + 1; j < n && j < i + 4; j++) {
                for (int k = j + 1; k < n && k < j + 4; k++) {
                    string a = s.substr(0, i);
                    string b = s.substr(i, j - i);
                    string c = s.substr(j, k - j);
                    string d = s.substr(k);

                    if (isValid(a) && isValid(b) && isValid(c) && isValid(d)) {
                        result.push_back(a + "." + b + "." + c + "." + d);
                    }
                }
            }
        }

        return result.empty() ? vector<string>{"-1"} : result;
    }

private:
    bool isValid(const string &part) {
        if (part.empty() || part.size() > 3 || (part.size() > 1 && part[0] == '0')) return false;
        int value = stoi(part);
        return value >= 0 && value <= 255;
    }

};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if(str.size()==0)
            cout << -1 << "\n";
        else{
            for (auto &u : str) {
                cout << u << "\n";
            }
        }
    
cout << "~" << "\n";
}
}
// } Driver Code Ends