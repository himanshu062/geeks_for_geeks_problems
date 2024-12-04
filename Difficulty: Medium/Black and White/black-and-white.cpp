//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends


//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
long long numOfWays(int N, int M)
{
    // write code here
    const long long MOD = 1e9 + 7;
    long long totalWays = (long long)N * M * (N * M - 1) % MOD; 
    long long attackWays = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i + 2 < N && j + 1 < M) attackWays++;
            if (i + 2 < N && j - 1 >= 0) attackWays++;
            if (i - 2 >= 0 && j + 1 < M) attackWays++;
            if (i - 2 >= 0 && j - 1 >= 0) attackWays++;
            if (i + 1 < N && j + 2 < M) attackWays++;
            if (i + 1 < N && j - 2 >= 0) attackWays++;
            if (i - 1 >= 0 && j + 2 < M) attackWays++;
            if (i - 1 >= 0 && j - 2 >= 0) attackWays++;
        }
    }

    attackWays %= MOD;
    return (totalWays - attackWays + MOD) % MOD;
}