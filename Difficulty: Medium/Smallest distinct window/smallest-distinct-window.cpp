//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here  
        int unique_chars = unordered_set<char>(str.begin(), str.end()).size();
        int min_len = INT_MAX;
        unordered_map<char, int> char_count;
        int left = 0;

        for (int right = 0; right < str.size(); right++) {
            char_count[str[right]]++;
            while (char_count.size() == unique_chars) {
                min_len = min(min_len, right - left + 1);
                char_count[str[left]]--;
                if (char_count[str[left]] == 0) {
                    char_count.erase(str[left]);
                }
                left++;
            }
        }
        return min_len;

    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends