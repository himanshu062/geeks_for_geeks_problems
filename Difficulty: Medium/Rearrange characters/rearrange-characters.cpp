//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;


// } Driver Code Ends



class Solution {
  public:
    string rearrangeString(string s) {
        int n = s.length();
        int count[26] = {0};
        for(char c : s) {
            count[c - 'a']++;
        }
        
        int maxCount = 0;
        char maxChar;
        for(int i = 0; i < 26; i++) {
            if(count[i] > maxCount) {
                maxCount = count[i];
                maxChar = 'a' + i;
            }
        }
        
        if(maxCount > (n + 1) / 2) {
            return "";
        }
        
        string result(n, ' ');
        int even = 0, odd = 1;
        
        while(count[maxChar - 'a'] > 0) {
            if(even < n) {
                result[even] = maxChar;
                even += 2;
            } else {
                result[odd] = maxChar;
                odd += 2;
            }
            count[maxChar - 'a']--;
        }
        
        for(int i = 0; i < 26; i++) {
            while(count[i] > 0) {
                if(even < n) {
                    result[even] = 'a' + i;
                    even += 2;
                } else {
                    result[odd] = 'a' + i;
                    odd += 2;
                }
                count[i]--;
            }
        }
        
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        string str1 = ob.rearrangeString(str);
        int flag = 1;
        int c[26] = {0};
        for (int i = 0; i < str.length(); i++)
            c[str[i] - 'a'] += 1;
        int f = 0;
        int x = (str.length() + 1) / 2;
        for (int i = 0; i < 26; i++) {
            if (c[i] > x)
                f = 1;
        }
        if (f) {
            if (str1 == "")
                cout << 0 << endl;
            else
                cout << 1 << endl;
        } else {
            int a[26] = {0};
            int b[26] = {0};
            for (int i = 0; i < str.length(); i++)
                a[str[i] - 'a'] += 1;
            for (int i = 0; i < str1.length(); i++)
                b[str1[i] - 'a'] += 1;

            for (int i = 0; i < 26; i++)
                if (a[i] != b[i])
                    flag = 0;

            for (int i = 0; i < str1.length(); i++) {
                if (i > 0)
                    if (str1[i - 1] == str1[i])
                        flag = 0;
            }
            if (flag == 1)
                cout << "1\n";
            else
                cout << "0\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends