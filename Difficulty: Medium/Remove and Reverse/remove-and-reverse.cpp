//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string S) {
        // code here
        unordered_map<char, int> freq;
        for (char ch : S) {
            freq[ch]++;
        }

        int left = 0, right = S.size() - 1;
        bool leftToRight = true;

        while (left < right) {
            if (leftToRight) {
                if (freq[S[left]] > 1) {
                    freq[S[left]]--;
                    S.erase(S.begin() + left);
                    leftToRight = !leftToRight;
                    right--;
                } else {
                    left++;
                }
            } else {
                if (freq[S[right]] > 1) {
                    freq[S[right]]--;
                    S.erase(S.begin() + right);
                    leftToRight = !leftToRight;
                    right--;
                } else {
                    right--;
                }
            }
        }
        
        if (!leftToRight) {
            reverse(S.begin(), S.end());
        }
        
        return S;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends