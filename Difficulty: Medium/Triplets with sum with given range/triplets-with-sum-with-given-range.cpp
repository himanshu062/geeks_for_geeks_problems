//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countTriplets(int Arr[], int N, int L, int R) {
        // code here
        sort(Arr, Arr + N);
        auto countLessThan = [&](int X) {
            int count = 0;
            for (int i = 0; i < N - 2; i++) {
                int left = i + 1, right = N - 1;
                while (left < right) {
                    int sum = Arr[i] + Arr[left] + Arr[right];
                    if (sum < X) {
                        count += (right - left);
                        left++;
                    } else {
                        right--;
                    }
                }
            }
            return count;
        };
        return countLessThan(R + 1) - countLessThan(L);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int Arr[N];
        for (int i = 0; i < N; i++) cin >> Arr[i];
        int L, R;
        cin >> L >> R;
        Solution obj;
        cout << obj.countTriplets(Arr, N, L, R) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends