//{ Driver Code Starts
                               //Initial Template for C++


#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
     vector<vector<int>> minDifference(vector<int>& arr, int n){
        //Code here
        vector<vector<int>> result;
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        int subsetSize = n / 2;
        vector<int> subset1, subset2;
        int minDiff = INT_MAX;
        for (int mask = 0; mask < (1 << n); ++mask) {
            vector<int> subset;
            int subsetSum = 0;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    subset.push_back(arr[i]);
                    subsetSum += arr[i];
                }
            }
            if (subset.size() == subsetSize || subset.size() == (n - subsetSize)) {
                int diff = abs(totalSum - 2 * subsetSum);
                if (diff < minDiff) {
                    minDiff = diff;
                    if (subset.size() == subsetSize) {
                        subset1 = subset;
                        subset2 = arr;
                        for (int num : subset) {
                            auto it = find(subset2.begin(), subset2.end(), num);
                            subset2.erase(it);
                        }
                    }
                }
            }
        }

        if (accumulate(subset1.begin(), subset1.end(), 0) > accumulate(subset2.begin(), subset2.end(), 0)) {
            swap(subset1, subset2);
        }

        result.push_back(subset1);
        result.push_back(subset2);
        return result;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution obj;
        vector<vector<int>> ans = obj.minDifference(arr,n);
        
        long long s1=0, s2=0;

        for(int i=0;i<ans[0].size();i++) s1+=ans[0][i];
        for(int i=0;i<ans[1].size();i++) s2+=ans[1][i];
        
        if(s1>s2) swap(s1,s2);

        cout<<s1<<"\n"<<s2<<"\n";
    
cout << "~" << "\n";
}
}
                               
// } Driver Code Ends