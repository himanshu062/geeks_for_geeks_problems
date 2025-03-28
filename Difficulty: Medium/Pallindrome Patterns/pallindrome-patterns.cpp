//{ Driver Code Starts



#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends



class Solution
{
	public:
		vector<string> all_plaindromes(string s)
		{
		    // Code here
		    unordered_map<char, int> freq;
        for (char c : s) freq[c]++;

        int oddCount = 0;
        char oddChar = '\0';
        string halfStr = "";
        for (auto &p : freq) {
            if (p.second % 2 != 0) {
                oddCount++;
                oddChar = p.first;
                if (oddCount > 1) return {};
            }
            halfStr += string(p.second / 2, p.first);
        }

        vector<string> result;
        sort(halfStr.begin(), halfStr.end());
        do {
            string palin = halfStr;
            if (oddChar != '\0') palin += oddChar;
            palin += string(halfStr.rbegin(), halfStr.rend());
            result.push_back(palin);
        } while (next_permutation(halfStr.begin(), halfStr.end()));

        return result;
		}
};




//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s;
    	cin >> s;
        Solution ob;
    	vector<string> ans  = ob.all_plaindromes(s);
    	cout<<"{ ";
    	for(auto i: ans)
    		cout << i << " ";
    	cout<<"}";
    	cout<<"\n";
    
cout << "~" << "\n";
}
	return 0;
}


// } Driver Code Ends