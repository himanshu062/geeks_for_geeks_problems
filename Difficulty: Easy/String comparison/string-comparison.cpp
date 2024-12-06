//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


int stringComparsion(string s1, string s2);


int main() 
{


   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s1, s2;
   		cin >> s1 >> s2;

   		
   		cout << stringComparsion(s1, s2) << "\n";
   	
cout << "~" << "\n";
}

    return 0;
}

// } Driver Code Ends



int stringComparsion(string s1,string s2)
{
    // Your code goes here
    unordered_map<string, int> priority = {
        {"a", 1}, {"b", 2}, {"c", 3}, {"d", 4}, {"e", 5},
        {"f", 6}, {"g", 7}, {"h", 8}, {"i", 9}, {"j", 10},
        {"k", 11}, {"l", 12}, {"m", 13}, {"n", 14}, {"ng", 15},
        {"o", 16}, {"p", 17}, {"q", 18}, {"r", 19}, {"s", 20},
        {"t", 21}, {"u", 22}, {"v", 23}, {"w", 24}, {"x", 25},
        {"y", 26}, {"z", 27}
    };

    int i = 0, j = 0, n1 = s1.size(), n2 = s2.size();
    while (i < n1 && j < n2) {
        string c1 = (i + 1 < n1 && s1[i] == 'n' && s1[i + 1] == 'g') ? "ng" : string(1, s1[i]);
        string c2 = (j + 1 < n2 && s2[j] == 'n' && s2[j + 1] == 'g') ? "ng" : string(1, s2[j]);

        if (priority[c1] < priority[c2]) return -1;
        if (priority[c1] > priority[c2]) return 1;

        i += (c1 == "ng") ? 2 : 1;
        j += (c2 == "ng") ? 2 : 1;
    }

    if (i < n1) return 1;
    if (j < n2) return -1;

    return 0;
}