//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long mergeAndCount(long long arr[], long long temp[], int left, int mid, int right) {
        int i = left; 
        int j = mid;  
        int k = left;
        long long inv_count = 0;

        while ((i <= mid - 1) && (j <= right)) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                inv_count += (mid - i);
            }
        }

        while (i <= mid - 1)
            temp[k++] = arr[i++];

        while (j <= right)
            temp[k++] = arr[j++];

        for (i = left; i <= right; i++)
            arr[i] = temp[i];

        return inv_count;
    }

    long long mergeSortAndCount(long long arr[], long long temp[], int left, int right) {
        int mid;
        long long inv_count = 0;
        if (right > left) {
            mid = (right + left) / 2;

            inv_count += mergeSortAndCount(arr, temp, left, mid);
            inv_count += mergeSortAndCount(arr, temp, mid + 1, right);

            inv_count += mergeAndCount(arr, temp, left, mid + 1, right);
        }
        return inv_count;
    }

    long long int inversionCount(long long arr[], int n) {
        long long temp[n];
        return mergeSortAndCount(arr, temp, 0, n - 1);
    }
};

//{ Driver Code Starts.

int main() {

    long long T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }

    return 0;
}

// } Driver Code Ends