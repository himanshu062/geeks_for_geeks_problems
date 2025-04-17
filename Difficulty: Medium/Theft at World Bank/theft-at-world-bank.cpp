//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
	public:
	long double maximumProfit(int N, long long C, vector<long long> w, vector<long long> p){
	    // Code here.
	    vector<pair<long double, int>> items;

	    for (int i = 0; i < N; i++) {
	        long long root = sqrt(w[i]);
	        if (root * root == w[i]) continue;
	        long double ratio = (long double)p[i] / w[i];
	        items.push_back({ratio, i});
	    }

	    sort(items.rbegin(), items.rend());

	    long double profit = 0.0;
	    for (auto &item : items) {
	        int i = item.second;
	        if (C >= w[i]) {
	            profit += p[i];
	            C -= w[i];
	        } else {
	            profit += (long double)p[i] * C / w[i];
	            break;
	        }
	    }

	    return profit;
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		long long C;
		cin >> n >> C;
		vector<long long > w(n), p(n);
		for(int i = 0; i < n; i++){
		    cin >> w[i] >> p[i];
		}
		Solution ob;
		long double ans = ob.maximumProfit(n, C, w, p);
		cout << fixed << setprecision(3) << ans << "\n";
	
cout << "~" << "\n";
}  
	return 0;
}
// } Driver Code Ends