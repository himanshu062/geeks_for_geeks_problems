//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

bool find4Numbers(int A[], int n, int X);

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, i, x;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin>>x;
        cout << find4Numbers(a, n, x) << endl;

    }
    return 0;
}
// } Driver Code Ends


//User function Template for C++

bool find4Numbers(int A[], int N, int X)  
{
    sort(A, A + N);
    for (int i = 0; i < N - 3; i++) {
        for (int j = i + 1; j < N - 2; j++) {
            int left = j + 1, right = N - 1;
            while (left < right) {
                int sum = A[i] + A[j] + A[left] + A[right];
                if (sum == X) return true;
                else if (sum < X) left++;
                else right--;
            }
        }
    }
    return false;
}