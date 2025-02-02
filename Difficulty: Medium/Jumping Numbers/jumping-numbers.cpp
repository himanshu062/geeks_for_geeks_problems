//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long jumpingNums(long long X) {
        // code here
        queue<long long> q;
        long long maxJumping = 0;

        for (int i = 1; i <= 9 && i <= X; i++) 
            q.push(i);

        while (!q.empty()) {
            long long num = q.front();
            q.pop();
            maxJumping = max(maxJumping, num);

            int lastDigit = num % 10;
            if (num * 10 + (lastDigit - 1) <= X && lastDigit > 0) 
                q.push(num * 10 + (lastDigit - 1));
            if (num * 10 + (lastDigit + 1) <= X && lastDigit < 9) 
                q.push(num * 10 + (lastDigit + 1));
        }

        return maxJumping;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.jumpingNums(X) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends