//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    vector<int> satisfyEqn(int A[], int N) {
        // code here
        unordered_map<int, pair<int, int>> sumMap;
        vector<int> res = {-1, -1, -1, -1};

        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                int sum = A[i] + A[j];

                if (sumMap.find(sum) != sumMap.end()) {
                    pair<int, int> p = sumMap[sum];
                    int x = p.first, y = p.second;

                    if (x != i && x != j && y != i && y != j) {
                        vector<int> temp = {x, y, i, j};
                        if (res[0] == -1 || temp < res) res = temp;
                    }
                } else {
                    sumMap[sum] = {i, j};
                }
            }
        }

        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        vector<int> ptr = ob.satisfyEqn(A,N);
        
        cout<<ptr[0]<<" "<<ptr[1]<<" "<<ptr[2]<<" "<<ptr[3]<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends