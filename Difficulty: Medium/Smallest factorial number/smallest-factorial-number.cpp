//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
        int findNum(int n)
        {
        //complete the function here
        if (n == 0) return 0;
        
        int low = 0, high = 5 * n, ans = -1;

        auto trailingZeroes = [](int x) {
            int count = 0;
            while (x >= 5) {
                count += x / 5;
                x /= 5;
            }
            return count;
        };

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (trailingZeroes(mid) >= n) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
        }
};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    
cout << "~" << "\n";
}
return 0;
}
// } Driver Code Ends