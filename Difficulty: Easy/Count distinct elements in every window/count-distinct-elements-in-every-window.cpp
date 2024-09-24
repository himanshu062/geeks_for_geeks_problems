//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        //code here.
        unordered_map<int, int> freq;
    vector<int> result;
    
    for (int i = 0; i < k; i++) freq[A[i]]++;
    result.push_back(freq.size());
    
    for (int i = k; i < n; i++) {
        freq[A[i - k]]--;
        if (freq[A[i - k]] == 0) freq.erase(A[i - k]);
        
        freq[A[i]]++;
        result.push_back(freq.size());
    }
    
    return result;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends