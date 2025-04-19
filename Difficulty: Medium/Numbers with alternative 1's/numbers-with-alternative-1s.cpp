//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends



class Solution{
	public:
	vector<int>numberWithNoConsecutiveOnes(int n){
	    // Code here
	    vector<int> ans;
        int maxNum = 1 << n;
        
        for(int i = 1; i < maxNum; i++) {
            bool valid = true;
            int num = i;
            
            while(num > 0) {
                if((num & 1) && (num & 2)) {
                    valid = false;
                    break;
                }
                num >>= 1;
            }
            
            if(valid) {
                ans.push_back(i);
            }
        }
        
        return ans;
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		vector<int>ans = ob.numberWithNoConsecutiveOnes(n);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends