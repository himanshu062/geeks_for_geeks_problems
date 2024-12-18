//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        int start=*max_element(arr.begin(),arr.end());
        int end=accumulate(arr.begin(),arr.end(),0);
        int ans=INT_MAX;
        int n=arr.size();
   
        if(k > n) return -1;
        while(start <= end)
        {
            int mid=start + (end-start)/2;
            
            int sum=0;
            int T=1;
            for(int i=0; i<n ;i++)
            {
                if(sum+arr[i] > mid)
                {
                    T++;
                    sum=arr[i];
                }
                
                else
                {
                    sum+=arr[i];
                }
            }
            
            if(T<=k)
            {
                end=mid-1;
                ans=min(ans,mid);
            }
            else{
                start=mid+1;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends