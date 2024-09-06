//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        vector<string> words;
        string word = "";
        for (char c : S) {
            if (c == '.') {
                words.push_back(word); 
                word = "";            
            } 
            else 
                word += c;            
        }
        words.push_back(word); 
        reverse(words.begin(), words.end());
        string result = "";
        for (int i = 0; i < words.size(); i++) {
            result += words[i];
            if (i != words.size() - 1) {
                result += "."; 
            }
        }
        
        return result;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends