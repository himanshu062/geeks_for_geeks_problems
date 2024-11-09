//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
        int countWords(string list[], int n)
        {
           //code here.
            unordered_map<string, int> wordCount;
        int count = 0;

        for (int i = 0; i < n; i++) {
            wordCount[list[i]]++;
        }

        for (auto& word : wordCount) {
            if (word.second == 2) count++;
        }

        return count;
        }

};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string list[n];
        for(int i=0;i<n;i++)
            cin>>list[i];
        Solution ob;    
        cout <<ob.countWords(list, n)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends