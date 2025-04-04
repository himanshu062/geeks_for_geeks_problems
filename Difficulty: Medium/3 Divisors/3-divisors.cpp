//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{
public:
    vector<int> threeDivisors(vector<long long> query, int q)
    {
        // Write your code here
        long long maxN = 0;
        for(int i = 0; i < q; i++) {
            maxN = max(maxN, query[i]);
        }
        long long limit = sqrt(maxN) + 1;
        vector<bool> isPrime(limit + 1, true);
        isPrime[0] = isPrime[1] = false;
        for(long long i = 2; i * i <= limit; i++) {
            if(isPrime[i]) {
                for(long long j = i * i; j <= limit; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        vector<int> primeCount(limit + 1, 0);
        for(int i = 2; i <= limit; i++) {
            primeCount[i] = primeCount[i-1] + (isPrime[i] ? 1 : 0);
        }
        vector<int> result(q);
        for(int i = 0; i < q; i++) {
            long long n = query[i];
            long long root = sqrt(n);
            result[i] = primeCount[root];
        }
        
        return result;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while(t--){
        int q;cin>>q;
        vector<long long> query(q);
        for(int i=0;i<q;i++){
            cin>>query[i];
        }
        Solution ob;
            
        vector<int> ans = ob.threeDivisors(query,q);
        for(auto cnt : ans) {
            cout<< cnt << endl;
        }
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends