//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function template for C++

class Solution {
  public:
    long long getSubstringWithEqual012(string str) {
        // code here
        unordered_map<string, int> mp;
        int c0 = 0, c1 = 0, c2 = 0;
        mp["0#0"] = 1;
        long long res = 0;
        for(char ch : str){
            if(ch == '0') c0++;
            else if(ch == '1') c1++;
            else c2++;
            string key = to_string(c1 - c0) + "#" + to_string(c2 - c1);
            res += mp[key];
            mp[key]++;
        }
        return res;
    }
};


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.getSubstringWithEqual012(s)<<endl;
	
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends