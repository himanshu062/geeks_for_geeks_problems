//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string S){
        //code
        vector<int> lastIndex(26, -1); 
        int left = 0; 
        int maxLength = 0;

    for (int right = 0; right < S.length(); right++) {
        char currentChar = S[right];
         if (lastIndex[currentChar - 'a'] >= left) {
            left = lastIndex[currentChar - 'a'] + 1;
        }

        lastIndex[currentChar - 'a'] = right;
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
        
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends