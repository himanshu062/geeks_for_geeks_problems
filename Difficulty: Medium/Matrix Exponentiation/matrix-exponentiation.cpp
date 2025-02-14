//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    const int MOD = 1e9 + 7;
    
    vector<vector<long long>> multiplyMatrix(vector<vector<long long>> &A, vector<vector<long long>> &B) {
        return {
            {(A[0][0] * B[0][0] + A[0][1] * B[1][0]) % MOD, (A[0][0] * B[0][1] + A[0][1] * B[1][1]) % MOD},
            {(A[1][0] * B[0][0] + A[1][1] * B[1][0]) % MOD, (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % MOD}
        };
    }

    vector<vector<long long>> matrixExpo(vector<vector<long long>> base, long long exp) {
        vector<vector<long long>> result = {{1, 0}, {0, 1}}; // Identity matrix

        while (exp) {
            if (exp % 2 == 1) 
                result = multiplyMatrix(result, base);
            base = multiplyMatrix(base, base);
            exp /= 2;
        }

        return result;
    }

    int FindNthTerm(long long int n) {
        if (n == 0 || n == 1) return 1;

        vector<vector<long long>> base = {{1, 1}, {1, 0}};
        vector<vector<long long>> res = matrixExpo(base, n-1);

        return (res[0][0] + res[0][1]) % MOD;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int n;
		cin >> n;
		Solution obj;
		int ans = obj.FindNthTerm(n);
		cout << ans << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends