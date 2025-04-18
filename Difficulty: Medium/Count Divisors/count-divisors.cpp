//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends



class Solution {
public:
	int DivCountSum(int n){
	    // Code here
	    vector<int> divCount(n + 1, 0);
	    for (int i = 1; i <= n; i++) {
	        for (int j = i; j <= n; j += i) {
	            divCount[j]++;
	        }
	    }
	    int sum = 0;
	    for (int i = 1; i <= n; i++) {
	        sum += divCount[i];
	    }
	    return sum;
	}

};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution obj;
		int ans = obj.DivCountSum(n);
		cout << ans << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends