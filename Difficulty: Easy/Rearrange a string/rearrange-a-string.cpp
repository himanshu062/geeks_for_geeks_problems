//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
  public:
    string arrangeString(string str)
    {
        //code here.
        vector<int> freq(26, 0);
        int sum = 0;
        for (char ch : str) {
            if (isdigit(ch)) sum += (ch - '0');
            else freq[ch - 'A']++;
        }
        
        string result;
        for (int i = 0; i < 26; i++) {
            result += string(freq[i], 'A' + i);
        }
        if (sum > 0) result += to_string(sum);
        return result;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout <<ob.arrangeString(s) << endl;
    
cout << "~" << "\n";
}
return 0;
}


// } Driver Code Ends