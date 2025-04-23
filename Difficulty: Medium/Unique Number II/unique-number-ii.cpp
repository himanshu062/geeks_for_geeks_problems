//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> singleNum(vector<int>& nums) {
        // Code here.
        int xorVal = 0;
        for(auto num: nums){
            xorVal ^= num;     
        }

        int mask = 1;           
        while(!(xorVal & 1)){   
            mask <<= 1;
            xorVal >>= 1;
        }
        
        vector<int> out(2,0);   
        for(auto num: nums){
           if((mask & num))    
                out[0] ^= num;
            else               
                out[1] ^= num;
        }
        sort(out.begin(),out.end());
        return out;
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.singleNum(arr);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends