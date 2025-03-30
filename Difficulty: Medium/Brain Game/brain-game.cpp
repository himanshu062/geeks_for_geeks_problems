//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
	public:
    bool brainGame(vector<int>nums) {
        // Code here.
        vector<int> grundy(1001, 0);
        for (int i = 2; i <= 1000; i++) {
            unordered_set<int> s;
            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    s.insert(grundy[i / j]);
                    if (j != i / j) s.insert(grundy[j]);
                }
            }
            while (s.count(grundy[i])) grundy[i]++;
        }
        int xor_sum = 0;
        for (int num : nums) xor_sum ^= grundy[num];
        return xor_sum != 0;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		bool ans = ob.brainGame(nums);
		if(ans)
			cout << "A\n";
		else cout << "B\n";
	
cout << "~" << "\n";
}  
	return 0;
}
// } Driver Code Ends