//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    vector<int> TopK(vector<int>& array, int k)
    {
        // code here
        unordered_map<int, int> freq;
        for (int id : array) freq[id]++;
        
        vector<pair<int, int>> freqList;
        for (auto& p : freq) freqList.push_back({p.second, p.first});
        
        sort(freqList.begin(), freqList.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return (a.first == b.first) ? (a.second > b.second) : (a.first > b.first);
        });
        
        vector<int> result;
        for (int i = 0; i < k; i++) result.push_back(freqList[i].second);
        
        return result;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k ;
        cin>>n;
        
        vector<int>array(n);
        
        for(int i=0; i<n; i++)
            cin>>array[i];
            
        cin>>k;
        
        Solution obj;
        vector<int> result = obj.TopK(array,k);
        
        for(int i=0; i<result.size();i++)
            cout<<result[i]<<" ";

        cout<<"\n";

    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends