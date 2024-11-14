//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    double distance(double x, double y, vector<pair<int, int>>& p) {
        double dist = 0;
        for (auto& point : p) {
            double dx = x - point.first;
            double dy = y - point.second;
            dist += sqrt(dx * dx + dy * dy);
        }
        return dist;
    }

    double findOptimumCost(tuple<int, int, int> l, vector<pair<int, int>> p, int n) {
        int a = get<0>(l), b = get<1>(l), c = get<2>(l);
        double low = -1e6, high = 1e6;
        while (high - low > 1e-6) {
            double mid1 = low + (high - low) / 3;
            double mid2 = high - (high - low) / 3;
            double y1 = (-a * mid1 - c) / b;
            double y2 = (-a * mid2 - c) / b;
            double dist1 = distance(mid1, y1, p);
            double dist2 = distance(mid2, y2, p);
            if (dist1 < dist2) high = mid2;
            else low = mid1;
        }
        double x = (low + high) / 2;
        double y = (-a * x - c) / b;
        return distance(x, y, p);
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    tuple<int,int,int>line;
	    int a, b, c;
	    cin >> a >> b >> c;
	    line = make_tuple(a, b, c);
	    int n;
	    cin >> n;
	    vector<pair<int,int>>points;
	    for(int i = 0 ; i < n; i++){
	        int x, y;
	        cin >> x >> y;
	        points.push_back({x, y});
	    }

	    Solution ob;
	    double ans = ob.findOptimumCost(line, points, n);

	    cout << fixed << setprecision(2) << ans << endl;
	
cout << "~" << "\n";
}
	return 0;
}

// } Driver Code Ends