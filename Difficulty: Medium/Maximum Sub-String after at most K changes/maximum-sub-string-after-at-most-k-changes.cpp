//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int characterReplacement(string s, int k){
		    // Code here
		    int n = s.size(), maxLen = 0, maxFreq = 0, left = 0;
            vector<int> freq(26, 0);

            for (int right = 0; right < n; right++) {
                maxFreq = max(maxFreq, ++freq[s[right] - 'A']);

                while ((right - left + 1) - maxFreq > k) {
                    freq[s[left] - 'A']--;
                    left++;
                }

                maxLen = max(maxLen, right - left + 1);
            }

            return maxLen;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		int k;
		cin >> k;
		Solution obj;
		int ans = obj.characterReplacement(s, k);
		cout << ans << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends