//{ Driver Code Starts
#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int numOfPairs(int X[], int Y[], int N) {
        // code here
        unordered_map<int, int> freqX, freqY;
        map<pair<int, int>, int> freqXY;
        int count = 0;

        for (int i = 0; i < N; i++) {
            int x = X[i], y = Y[i];
            count += freqX[x] + freqY[y] - 2 * freqXY[{x, y}];
            freqX[x]++;
            freqY[y]++;
            freqXY[{x, y}]++;
        }

        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        int X[N], Y[N];
        
        for(int i=0; i<N; i++)
            cin>>X[i];
        for(int i=0; i<N; i++)
            cin>>Y[i];

        Solution ob;
        cout << ob.numOfPairs(X,Y,N) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends