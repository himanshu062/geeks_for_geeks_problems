//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        int closestToZero(int arr[], int n)
        {
            // your code here
            sort(arr, arr + n); 
        int left = 0, right = n - 1;
        int closestSum = INT_MAX;

        while (left < right) {
            int sum = arr[left] + arr[right];
            if (abs(sum) < abs(closestSum) || (abs(sum) == abs(closestSum) && sum > closestSum)) 
            closestSum = sum; 
            if (sum < 0) 
            left++; 
            else 
            right--; 
        }
        return closestSum;
        }
};

//{ Driver Code Starts.
int main ()
{
    int t; 
    cin >> t;
    while (t--)
    {
        int n; 
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.closestToZero(arr, n) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends